#include "Course.h"

Course::Course() : points(0), isMandatory(true), semester(1)
{

}

Course::Course(unsigned coursePoints) : points(coursePoints), isMandatory(true), semester(1)
{

}

Course::Course(unsigned coursePoints, bool isCourseMandatory) : points(coursePoints),
 isMandatory(isCourseMandatory), semester(1)
{

}

Course::Course(unsigned coursePoints, bool isCourseMandatory, unsigned courseSemester) :
points(coursePoints), isMandatory(isCourseMandatory), semester(courseSemester)
{

}