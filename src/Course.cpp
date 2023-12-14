#include "Course.h"

Course::Course(std::string courseName, unsigned coursePoints, bool courseIsMandatory,
unsigned courseSemester) : name(courseName), points(coursePoints), isMandatory(courseIsMandatory),
semester(courseSemester)
{

}