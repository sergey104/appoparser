#include <cstdlib>
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h> // or something

using namespace std;

void Indent(ostream& ofs, int indent) {
    for (int i=0; i<indent; i++)
        ofs << ' ';
}

void MyPrint(ostream& ofs, const Json::Value& val, int indent=0) {
    switch (val.type()) {
        case Json::nullValue: ofs << "null"; break;
        case Json::booleanValue: ofs << (val.asBool() ? "true" : "false"); break;
        case Json::intValue: ofs << val.asLargestInt(); break;
        case Json::uintValue: ofs << val.asLargestUInt(); break;
        case Json::realValue: ofs << val.asDouble(); break;
        case Json::stringValue: ofs << '"' << val.asString() << '"'; break;
        case Json::arrayValue: {
            Json::ArrayIndex size = val.size();
            if (size == 0)
                ofs << "[]";
            else {
                ofs << "[\n";
                int newIndent = indent + 4;
                for (Json::ArrayIndex i=0; i<size; i++) {
                    Indent(ofs, newIndent);
                    MyPrint(ofs, val[i], newIndent);
                    ofs << (i + 1 == size ? "\n" : ",\n");
                }
                Indent(ofs, indent);
                ofs << ']';
            }
            break;
        }
        case Json::objectValue: {
            if (val.empty())
                ofs << "{}";
            else {
                ofs << "{\n";
                int newIndent = indent + 4;
                vector<string> keys = val.getMemberNames();
                for (size_t i=0; i<keys.size(); i++) {
                    Indent(ofs, newIndent);
                    const string& key = keys[i];
                    ofs << '"' << key << '"' << " : ";
                    MyPrint(ofs, val[key], newIndent);
                    ofs << (i + 1 == keys.size() ? "\n" : ",\n");
                }
                Indent(ofs, indent);
                ofs << '}';
            }
            break;
        }
        default :
            cerr << "Wrong type!" << endl;
            exit(0);
    }
}

int main() {
    ifstream ifs("/home/fil/appobel.txt");
    Json::Value val;
    ifs >> val;
    MyPrint(cout, val);
    cout << '\n';
}
