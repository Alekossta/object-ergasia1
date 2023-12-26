At the start of the program we will load the starting data from our "startingData" folder

Then our data will be read/write from the files in the "data" folder

# Files format

in the starting data we will have no ids.

## Course

courseId,courseName,coursePoints,courseIdMandatory,courseSemester

## Professor

professorId,professorName,professorAge,courseId1,courseId2,...,courseIdN

## Student

studentId,studentName,studentAge,passedCourseId1,passedCourseId1Grade,passedCourseId2,passedCourseId2Grade,...,passedCourseIdN,passedCourseIdNGrade

## Time data

year,isWinterSemester

(students and professors are in the same id "pool")