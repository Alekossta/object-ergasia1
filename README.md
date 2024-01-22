# Εργασία 2 Αντικειμενοστραφή Προγραμματισμού

## Μέλη:
- Alexandros Giannoudovardis [sdi2200264]
- Alexandros Stavrinoudakis [sdi2200171]

## Οδηγίες

- Την πρώτη φορά που θα τρέξει το πρόγραμμα, θα πρέπει το /data/firstTimeRunning.csv να είναι "true"
    - Έτσι θα φορτωθούν οι "default" καθηγητές και μαθητές (/data/startingData)
    - Εναλλακτικά, αν θέλουμε να ξεκινήσουμε χωρίς αρχικά δεδομένα, θέτουμε το /data/firstTimeRunning.csv σε "false" πριν την πρώτη εκτέλεση του προγράμματος
- Από εκεί και πέρα, η φόρτωση/αποθήκευση θα γίνεται στο /data/
- `make main`
- `./main`
- Θα πρέπει ο χρήστης να θέσει τους καθηγητές του κάθε μαθήματος κάθε εξάμηνο [4], πριν να μπορεί να βάλει μαθητές να το "παρακολουθήσουν" [5]
- Η βαθμολόγηση/εξεταστική γίνεται μέσω της επιλογής [s] αφού αντιστοιχιστούν τα μαθήματα με καθηγητές/μαθητές
- Μετά την βαθμολόγηση, ξαναπατάμε [s] για να προχωρήσουμε στο επόμενο εξάμηνο
- Η έξοδος του προγράμματος γίνεται μέσω της επιλογής [0]

## Σημαντικές πληροφορίες

> Αν γίνει έξοδος χωρίς την χρήση του [0] θα υπάρξει memory leak και δεν θα αποθηκευτεί οποιαδήποτε αλλαγή έγινε στα δεδομένα.

> Δεδομένα που αποθηκεύονται: μαθήματα, μαθητές, καθηγητές, ποιά μαθήματα έχει ο κάθε καθηγητής, ποια μαθήματα έχει ΠΕΡΑΣΕΙ ο κάθε μαθητής και με τι βαθμό, τρέχον έτος, τρέχον εξάμηνο.

> Δεδομένα που __ΔΕΝ__ αποθηκεύονται: βαθμοί εξαμήνου σε μη περασμένα μαθήματα.

> Επιλογή [x] : εκτυπώνονται όλοι οι καθηγητές, οι μαθητές και τα μαθήματα του τρέχοντος εξαμήνου.

> Επιλογή [r] : διαγράφονται όλα τα δεδομένα και το /data/firstTimeRunning.csv γίνεται πάλι "true".

## Files format

- Course\
`courseId,courseName,coursePoints,courseIsMandatory,courseSemester`

- Professor\
`professorId,professorName,professorAge,courseId1,courseId2,...,courseIdN`

- Student\
`studentId,studentName,studentAge,passedCourseId1,passedCourseId1Grade,passedCourseId2,passedCourseId2Grade,...,passedCourseIdN,passedCourseIdNGrade`

- Time data\
`year,isWinterSemester`

> Note: In the starting data we will have no ids.

> Note: Students and professors are in the same id "pool".
