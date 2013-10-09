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

#ifndef RHINO_XR4_H_53DOY91C
#define RHINO_XR4_H_53DOY91C

#include "matrix.hpp"
#include "exception.hpp"

#ifndef PI
#define PI 3.14159265
#endif

#ifndef TOL
#define TOL 0.0001 // tolerance
#endif

real deg2rad(real angle);
real rad2deg(real angle);
real nullify(real num);
float truncate(float num);
real sign(real num);

struct JointAngles {
    real t1, t2, t3, t4, t5;
    
            JointAngles() {};
            JointAngles(real t1, real t2, real t3, real t4, real t5);
    void    print();
};

struct Range {
    real min, max;
    Range(real min, real max);
};

struct RhinoXR4 {
    JointAngles angles;
public:
                RhinoXR4();
    Matrix      dirkin(JointAngles &angles);
    JointAngles invkin(Matrix &matrix);
    JointAngles invkin2(Matrix &matrix);
    real        deg2steps(real deg, char motor, bool correct=true);
    real        steps2deg(real steps, char motor, bool correct=true);
    Range       jointRangeDeg(char motor, bool correct=false);
    Range       jointRangeSteps(char motor);
};

class InvalidMotor : Exception
{
public:
    InvalidMotor();
};

#endif /* end of include guard: RHINO_XR4_H_53DOY91C */
