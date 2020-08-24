#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<string> contacts(10000000);
    for(size_t i=0;i<10000000;i++)
	contacts[i]="N/A";
    for (size_t i = 0; i < queries.size(); ++i) {
        if (queries[i].type == "add") {
            // if we already have contact with such number,
            // we should rewrite contact's name
                contacts[queries[i].number]=queries[i].name;
                }
                
            // otherwise, just add it
        else if (queries[i].type == "del") {
                    	contacts[queries[i].number] = "N/A";
		}
        else {
            string response = "not found";
            if (contacts[queries[i].number] != "N/A") 
                    response = contacts[queries[i].number];
            result.push_back(response);
        }
    }
     return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
