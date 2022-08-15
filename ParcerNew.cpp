//
// Created by Sean Grady on 8/9/2022.
//
#include <fstream>
#include "ParcerNew.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <map>
#include <sstream>
#include "include/rapidjson/document.h"
#include "include/rapidjson/istreamwrapper.h"
#include "Doc.h"
#include <set>
#include <cstdio>

using namespace rapidjson;
void ParcerNew::readJSON(const string& fileName){
    loadStop();
    /*for each folder in jsons:
     * for each json file in folder:
     * load and parse title and content using the functions we alreay made
     */
    ifstream file(fileName.c_str());
    if(!file.is_open()){
        cout << "didnt open input file" << endl;
        return;
    }
    ostringstream tmp;
    tmp<<file.rdbuf();
    string content = tmp.str();
    Document d;
    d.Parse(content.c_str());
    //cout << d["title"].GetString() << endl;
    string title = d["title"].GetString();
    insertWords(title);
    string text = d["text"].GetString();
    insertWords(text);



    int counter = 1;
    const rapidjson::Value& attributes = d["entities"]["persons"];
    // using iterator to find all author info
    for (rapidjson::Value::ConstValueIterator itr = attributes.Begin(); itr != attributes.End(); ++itr) {
        const rapidjson::Value &attribute = *itr;
        for (rapidjson::Value::ConstMemberIterator itr2 = attribute.MemberBegin(); itr2 != attribute.MemberEnd(); ++itr2) {
            if (itr2->name.IsString() && itr2->value.IsString()) {
                if (strlen(itr2->value.GetString()) > 0) {
                    string person = (itr2->name.GetString());
                    cout << person;
                    insertPerson(person);
                    cout << "  "<<itr2->name.GetString() << " : " << itr2->value.GetString() << endl;
                }
            }
            counter++;
        }
    }
    personAVL.printTree();
//    wordsAVL.printTree();

    //cout << content << endl;
}

void ParcerNew::loadStop() {
    ifstream inputStop;
    inputStop.open("../stopWords.txt");
    if(!inputStop.is_open()){
        cout << "didnt open stop words" << endl;
        return;
    }
    string word;
    while(getline(inputStop, word)){
        stopWords.insert(word);
    }
    //cout << "stopWordsSize: " << stopWords.size();
}
void ParcerNew::insertPerson(string& data){
    string current = "";
    for(auto x : data) {
        if(x == ' '){
            personAVL.Insert(current, 0);
            current = "";
        } else current += x;
    }
}
void ParcerNew::insertOrg(string& data){
    string current = "";
    for(auto x : data){
        if(x == ' '){
            orgAVL.Insert(current,0);
            current = "";

        } else current += x;
    }
}
void ParcerNew::insertWords(string& data) {
    string current = "";
    for(auto x : data){
        if(x == ' '){
            if(stopWords.find(current) == stopWords.end()){
                Porter2Stemmer::stem(current);
                wordsAVL.Insert(current, 0);
            }
            current = "";
        } else current += x;
    }
    wordsAVL.Insert(current, 0);
}
