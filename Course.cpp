#include "Course.h"

Course::Course(unsigned coursePoints) : points(coursePoints), isMandatory(true)
{

}

Course::Course(unsigned coursePoints, bool isCourseMandatory) : points(coursePoints), isMandatory(isCourseMandatory)
{

}