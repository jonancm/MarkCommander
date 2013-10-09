// Copyright 2011 Jonán C. Martín
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "rhino_xr4.hpp"

#include <cmath>

#include <iostream>
using namespace std;

real nullify(real num)
{
    if (abs(num) < TOL)
        return 0.0;
    else
        return num;
}

float truncate(float num)
{
    long x = 1000 * num;
    float y = (float)x / (float)1000;
    return y;
}

real sign(real num)
{
    return (num < 0.0 ? -1 : 1);
}

real deg2rad(real angle)
{
    return (PI*angle)/180;
}

real rad2deg(real angle)
{
    return (angle*180)/PI;
}

JointAngles::JointAngles(real t1, real t2, real t3, real t4, real t5)
{
    this->t1 = deg2rad(t1);
    this->t2 = deg2rad(t2);
    this->t3 = deg2rad(t3);
    this->t4 = deg2rad(t4);
    this->t5 = deg2rad(t5);
}

Range::Range(real min, real max)
{
    this->min = min;
    this->max = max;
}

void JointAngles::print()
{
    cout << "t1 = " << rad2deg(t1) << " degrees" << endl;
    cout << "t2 = " << rad2deg(t2) << " degrees" << endl;
    cout << "t3 = " << rad2deg(t3) << " degrees" << endl;
    cout << "t4 = " << rad2deg(t4) << " degrees" << endl;
    cout << "t5 = " << rad2deg(t5) << " degrees" << endl;
}

RhinoXR4::RhinoXR4()
{
    angles.t1 = 0;
    angles.t2 = 0;
    angles.t3 = 0;
    angles.t4 = 0;
    angles.t5 = 0;
}

Matrix RhinoXR4::dirkin(JointAngles &angles)
{
    Matrix matrix(4, 4);
    
    real d1   = 260;
    real a2   = 228.6;
    real a3   = 228.6;
    real a4   = 9.5;
    real d5   = 165;
    
    real s1   = sin(angles.t1);
    real c1   = cos(angles.t1);
    real s2   = sin(angles.t2);
    real c2   = cos(angles.t2);
    real s5   = sin(angles.t5);
    real c5   = cos(angles.t5);
    real s23  = sin(angles.t2 + angles.t3);
    real c23  = cos(angles.t2 + angles.t3);
    real s234 = sin(angles.t2 + angles.t3 + angles.t4);
    real c234 = cos(angles.t2 + angles.t3 + angles.t4);
    
    matrix.at(1, 1) = nullify(s1*s5 + c5*c1*c234);
    matrix.at(1, 2) = nullify(c5*s1 - s5*c1*c234);
    matrix.at(1, 3) = nullify(c1*s234);
    matrix.at(1, 4) = nullify(c1*(d5*s234 + a2*c2 + a3*c23 + a4*c234));
    
    matrix.at(2, 1) = nullify(c5*s1*c234 - c1*s5);
    matrix.at(2, 2) = nullify(-c1*c5 - s5*s1*c234);
    matrix.at(2, 3) = nullify(s1*s234);
    matrix.at(2, 4) = nullify(s1*(d5*s234 + a2*c2 + a3*c23 + a4*c234));
    
    matrix.at(3, 1) = nullify(c5*s234);
    matrix.at(3, 2) = nullify(-s5*s234);
    matrix.at(3, 3) = nullify(-c234);
    matrix.at(3, 4) = nullify(d1 - d5*c234 + a2*s2 + a3*s23 + a4*s234);
    
    matrix.at(4, 1) = 0;
    matrix.at(4, 2) = 0;
    matrix.at(4, 3) = 0;
    matrix.at(4, 4) = 1;
    
    return matrix;
}

JointAngles RhinoXR4::invkin(Matrix &matrix)
{
    JointAngles angles;
    real A, B, alph, sa, s1, c1, s3, c3;

    real d1 = 260;
    real a2 = 228.6;
    real a3 = 228.6;
    real a4 = 9.5;
    real d5 = 165;

    // row 1
    real r11 = matrix.at(1, 1);
    real r12 = matrix.at(1, 2);
    real r13 = matrix.at(1, 3);
    qDebug("r11 = %f\tr12 = %f\tr13 = %f", (double)r11, (double)r12, (double)r13);
    // row 2
    real r21 = matrix.at(2, 1);
    real r22 = matrix.at(2, 2);
    real r23 = matrix.at(2, 3);
    qDebug("r21 = %f\tr22 = %f\tr23 = %f", (double)r21, (double)r22, (double)r23);
    // row 3
    real r33 = matrix.at(3, 3);
    // row 4
    real t1  = matrix.at(1, 4);
    real t2  = matrix.at(2, 4);
    real t3  = matrix.at(3, 4);

    angles.t1 = atan2(t2, t1);
    qDebug("t1 = %f rad (%f deg)", (double)angles.t1, (double)rad2deg(angles.t1));
    qDebug("deg2rad(jointRangeDeg('F').min) = %f", (double)deg2rad(jointRangeDeg('F', false).min));
    qDebug("deg2rad(jointRangeDeg('F').max) = %f", (double)deg2rad(jointRangeDeg('F', false).max));
    if (angles.t1 < deg2rad(jointRangeDeg('F').min) || angles.t1 > deg2rad(jointRangeDeg('F').max))
        angles.t1 += -sign(angles.t1)*PI; // t1 + 180º
    qDebug("t1 = %f rad (%f deg)", (double)angles.t1, (double)rad2deg(angles.t1));
    s1 = sin(angles.t1);
    qDebug("s1 = %f", (double)s1);
    c1 = cos(angles.t1);
    qDebug("c1 = %f", (double)c1);

    angles.t5 = atan2(s1*r11 - c1*r21, s1*r12 - c1*r22);
    qDebug("s1*r11 = %f", (double)(s1*r11));
    qDebug("c1*r21 = %f", (double)(c1*r21));
    qDebug("s1*r11 - c1*r21 = %f", (double)(s1*r11 - c1*r21));
    qDebug("s1*r12 = %f", (double)(s1*r12));
    qDebug("c1*r22 = %f", (double)(c1*r22));
    qDebug("s1*r12 - c1*r22 = %f", (double)(s1*r12 - c1*r22));
    qDebug("t5 = %f rad (%f deg)", (double)angles.t5, (double)rad2deg(angles.t5));

    alph = atan2(c1*r13+s1*r23, -r33);
    qDebug("alpha = %f (%f deg)", (double)alph, (double)rad2deg(alph));
    sa = sin(alph);
    qDebug("sa = %f", (double)sa);

    // calculation of th3
    A = t3 - d1 - d5*r33 - a4*sa;
    qDebug("A = %f", (double)A);
    if (nullify(s1) == 0.0)
        B = t1/c1 - d5*sa + a4*r33;
    else
        B = t2/s1 - d5*sa + a4*r33;
    qDebug("B = %f", (double)B);
    qDebug("(A*A + B*B - a2*a2 - a3*a3) = %f", (double)(A*A + B*B - a2*a2 - a3*a3));
    qDebug("(A*A + B*B - a2*a2 - a3*a3) / (2*a2*a3) = %f", (double)((A*A + B*B - a2*a2 - a3*a3) / (2*a2*a3)));
    real tmp = (A*A + B*B - a2*a2 - a3*a3) / (2*a2*a3);
    tmp = tmp > 1.0 ? 1.0 : tmp;
    angles.t3 = -acos(truncate(tmp)); // elbow-up solution
    qDebug("t3 = %f (%f deg)", (double)angles.t3, (double)rad2deg(angles.t3));
    s3 = sin(angles.t3);
    qDebug("s3 = %f", (double)s3);
    c3 = cos(angles.t3);
    qDebug("c3 = %f", (double)c3);

    // calculation of th2
    qDebug("A*(a2+a3*c3) = %f", (double)(A*(a2+a3*c3)));
    qDebug("B*a3*s3 = %f", (double)(B*a3*s3));
    qDebug("A*(a2+a3*c3)-B*a3*s3 = %f", (double)(A*(a2+a3*c3)-B*a3*s3));
    qDebug("B*(a2+a3*c3) = %f", (double)(B*(a2+a3*c3)));
    qDebug("A*a3*s3 = %f", (double)(A*a3*s3));
    qDebug("B*(a2+a3*c3)+A*a3*s3 = %f", (double)(B*(a2+a3*c3)+A*a3*s3));
    qDebug("A*(a2+a3*c3)-B*a3*s3 / B*(a2+a3*c3)+A*a3*s3 = %f", (double)((A*(a2+a3*c3)-B*a3*s3) / (B*(a2+a3*c3)+A*a3*s3)));
    angles.t2 = atan2(A*(a2+a3*c3)-B*a3*s3, B*(a2+a3*c3)+A*a3*s3);
    qDebug("t2 = %f (%f deg)", (double)angles.t2, (double)rad2deg(angles.t2));

    // calculation of th4
    angles.t4 = alph - angles.t2 - angles.t3;

    angles.t1 = nullify(angles.t1);
    angles.t2 = nullify(angles.t2);
    angles.t3 = nullify(angles.t3);
    angles.t4 = nullify(angles.t4);
    angles.t5 = nullify(angles.t5);

    return angles;
}

JointAngles RhinoXR4::invkin2(Matrix &matrix)
{
    JointAngles angles;
    real t234, s234, c234, A, B, s1, c1, s3, c3;
    
    real d1 = 260;
    real a2 = 228.6;
    real a3 = 228.6;
    real a4 = 9.5;
    real d5 = 165;
    
    // N
    real nx = matrix.at(1, 1);
    real nz = matrix.at(3, 1);
    // S
    real sx = matrix.at(1, 2);
    real sz = matrix.at(3, 2);
    // A
    real r13 = matrix.at(1, 3);
    real r23 = matrix.at(2, 3);
    real az = matrix.at(3, 3);
    real &r33 = az;
    // P
    real px = matrix.at(1, 4);
    real py = matrix.at(2, 4);
    real pz = matrix.at(3, 4);

    //qDebug("az = %f", (double)az);
    //t234 = acos(-az);
    //s234 = sin(t234);
    //c234 = cos(t234);

    angles.t1 = atan2(py, px);
    if (angles.t1 < deg2rad(jointRangeDeg('F', false).min) || angles.t1 > deg2rad(jointRangeDeg('F', false).max))
        angles.t1 += PI; // t1 + 180º
    qDebug("t1 = %f (%f deg)", (double)angles.t1, (double)rad2deg(angles.t1));
    s1 = sin(angles.t1);
    c1 = cos(angles.t1);

    t234 = atan2(c1*r13+s1*r23, -r33);
    qDebug("t234 = %f (%f deg)", (double)t234, (double)rad2deg(t234));
    s234 = sin(t234);
    c234 = cos(t234);

    if (nullify(s234) == 0.0)
    {
        if (c234 > 0)
            angles.t5 = angles.t1 - atan2(sx, nx);
        else
            angles.t5 = -angles.t1 + atan2(sx, -nx);
    }
    else
        angles.t5 = atan2(-sz, nz);

    A = pz - a4*s234 + d5*c234 - d1;
    B = px*c1 + py*s1 - a4*c234 - d5*s234;

    real num = A*A + B*B - a2*a2 - a3*a3;
    real den = 2*a2*a3;
    qDebug("num / den = %f", (double)(num/den));
    angles.t3 = -acos(truncate(num / den));
    s3 = sin(angles.t3);
    c3 = cos(angles.t3);

    num = A*(a2 + a3*c3) - B*a3*s3;
    den = A*a3*s3 + B*(a2 + a3*c3);
    angles.t2 = atan2(num, den);

    angles.t4 = t234 - angles.t2 - angles.t3;
    
    angles.t1 = nullify(angles.t1);
    angles.t2 = nullify(angles.t2);
    angles.t3 = nullify(angles.t3);
    angles.t4 = nullify(angles.t4);
    angles.t5 = nullify(angles.t5);
    
    return angles;
}

real RhinoXR4::deg2steps(real deg, char motor, bool correct)
{
    switch (motor)
    {
    case 'B':
        if (correct)
            return (deg - 180)*12.8;
        else
            return deg*12.8;
    case 'C':
        return deg*35.2736;
    case 'D':
        if (correct)
            return (deg + 90)*35.2736;
        else
            return deg*35.2736;
    case 'E':
        if (correct)
            return (deg - 90)*35.2736; // Home de la cinemática: 1196 \simeq 1200
        else
            return deg*35.2736; // Home de la cinemática: 1196 \simeq 1200
    case 'F':
        if (correct)
            return (deg - 90)*17.6368;
        else
            return deg*17.6368;
    default:
        throw new InvalidMotor();
    }
}

real RhinoXR4::steps2deg(real steps, char motor, bool correct)
{
    switch (motor)
    {
    case 'B':
        if (correct)
            return steps*0.078125 + 180;
        else
            return steps*0.078125;
    case 'C':
        return steps*0.02834981402522;
    case 'D':
        if (correct)
            return steps*0.02834981402522 - 90;
        else
            return steps*0.02834981402522;
    case 'E':
        if (correct)
            return steps*0.02834981402522 + 90; // Home de la cinemática: 1196 \simeq 1200
        else
            return steps*0.02834981402522; // Home de la cinemática: 1196 \simeq 1200
    case 'F':
        if (correct)
            return steps*0.05669962805044 + 90;
        else
            return steps*0.05669962805044;
    default:
        throw new InvalidMotor();
    }
}

Range RhinoXR4::jointRangeDeg(char motor, bool correct)
{
    switch (motor)
    {
    case 'B':
        return Range(steps2deg(-20000, 'B', true), steps2deg(20000, 'B', true));
    case 'C':                             
        return Range(steps2deg(-2800, 'C', true), steps2deg(8200, 'C', true));
    case 'D':                             
        return Range(steps2deg(-2200, 'D', true), steps2deg(5115, 'D', true));
    case 'E':                             
        return Range(steps2deg(-550, 'E', true), steps2deg(4300, 'E', true));
    case 'F':                             
        return Range(steps2deg(-3056, 'F', true), steps2deg(3056, 'F', correct));
    default:
        throw new InvalidMotor();
    }
}

Range RhinoXR4::jointRangeSteps(char motor)
{
    switch (motor)
    {
    case 'B':
        return Range(-20000, 20000);
    case 'C':
        return Range(-2800, 8200);
    case 'D':
        return Range(-2200, 5115);
    case 'E':
        return Range(-550, 4300);
    case 'F':
        return Range(-3056, 3056);
    default:
        throw new InvalidMotor();
    }
}

InvalidMotor::InvalidMotor()
{
    _description = QObject::tr("Invalid motor letter");
    setMessage(QObject::tr("Invalid mottor letter: motor letter must be between B and F"));
}
