At the start of the program we will load the starting data from our "startingData" folder

Then our data will be read/write from the files in the "data" folder

# Files format

## Course

courseId,courseName,coursePoints,courseIdMandatory,courseSemester
studentId1,studentId2,...,studentIdN
professorId1,professorId2,...,professorIdN

## Professor

professorId,professorName,professorAge
courseId1,courseId2,...,courseIdN

## Student

studentId,studentName,studentAge
courseId1,courseId2,...,courseIdN

(students and professors are in the same id "pool")