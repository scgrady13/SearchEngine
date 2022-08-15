//
// Created by Sean Grady on 8/9/2022.
//

#ifndef SEARCHENGINE_PARCERNEW_H
#define SEARCHENGINE_PARCERNEW_H
#include "AVLTree.h"
#include <unordered_set>
#include <experimental/filesystem>
#include "include/rapidjson/filereadstream.h"
#include "porter2_stemmer.h"
class ParcerNew {
public:
    ParcerNew(){

    }
    void readFiles(string fileName);
    void readJSON(const string& fileName);

private:
    AVLTree wordsAVL;
    AVLTree personAVL;
    AVLTree orgAVL;
    unordered_set<string> stopWords;

    void readJSON(string fileName, int docID);
    inline void insertWords(string& data);
    void loadStop();

    void insertOrg(string &data);

    void insertPerson(string &data);
};


#endif //SEARCHENGINE_PARCERNEW_H
