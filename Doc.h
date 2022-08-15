//
// Created by Sean Grady on 8/9/2022.
//

#ifndef SEARCHENGINE_DOC_H
#define SEARCHENGINE_DOC_H

#include <string>
using namespace std;
class Doc {
private:
    string title;
    string date;
    string pub;
    string text;

public:
    Doc(){
        title ="";
    }
    Doc(const string&,const string&, const string&);
    void setTitle(const string& titleIn){
        title = titleIn;
    }
    void setText(const string& textIn){
        text = textIn;
    }
    void setDate(const string& dateIn){
        date = dateIn;
    }
    void setPub(const string& pubIn){
        pub = pubIn;
    }

};



#endif //SEARCHENGINE_DOC_H
