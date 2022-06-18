//
// Created by Ilia Belov on 09.06.2022.
//

#ifndef RAYTRACING_SUPPORT_H
#define RAYTRACING_SUPPORT_H

#define F_2_PI      6.28318530718f                           /* 2*pi           */
#define F_PI        3.14159265358979323846264338327950288f   /* pi             */
#define F_PI_2      1.57079632679489661923132169163975144f   /* pi/2           */
#define F_PI_4      0.785398163397448309615660845819875721f  /* pi/4           */
#define F_PI_8      0.392699081698724154807830422909937860f  /* pi/8           */
#define F_PI_16      0.392699081698724154807830422909937860f/2  /* pi/8           */
#define F_PI_32      0.392699081698724154807830422909937860f/4  /* pi/8           */

float sqr(float x);

void normalize_angle(float& a);

float operator ""_o(unsigned long long int x);

float operator ""_o(long double x);

#endif //RAYTRACING_SUPPORT_H
