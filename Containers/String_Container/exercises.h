#ifndef EXERCISES_H
#define EXERCISES_H

    #include <string>
    using std::string;
    #include <vector>
    using std::vector;

    void verifyExercises(void);

    void toUpper(string& origin);
    void eraseUpperLettersFrom(string& origin);
    string instantiateStringObjectFromVector(const vector<char>& charvec);

#endif  /* EXERCISES_H */
