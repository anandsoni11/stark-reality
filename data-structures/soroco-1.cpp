#include <bits/stdc++.h>
#include <regex>
using namespace std;

string solution(vector <int> array) {
    int l = array.size();
    int start = 0;
    int current = 0;
    int next = 0;
    string res = "";
    if (l <= 0) return res;
    if (l == 1) {
        res += to_string(array[0]);
        return res;
    }
    
    while (current < l) {
        if (current+2 < l && array[current] - array[current+2] == -2) {
            current = current+2;
            next = current+1;
            while(next<l && array[current] - array[next] == -1) next++;
            res += to_string(array[start]);
            res += "-";
            res += to_string(array[next-1]);
            current = next;
            next++;
            start = current;
        }
    
        else {
            res += to_string(array[current]);
            current++;
            start = current;
            next++;
        }
        if (current < l) res+=",";
    }
    return res;
}

string find_phone_number(string text) {
    string res = "NONE";
    regex rg1("[[:digit:]]{3}-[[:digit:]]{3}-[[:digit:]]{4}");
    regex rg2("\\([[:digit:]]{3}\\) [[:digit:]]{3}-[[:digit:]]{4}");
    smatch match;
    if (regex_search(text, match, rg1) || regex_search(text, match, rg2)) {
        res = match[0];
    }
    return res;
}

std::string dedup(std::string input_str, int chunk_size) {
    // Write your code here.
    string res="";
    unordered_map<string, int> chunk_map;
    for (int i=0; i<input_str.length(); i=i+chunk_size) {
        string chunk = input_str.substr(i,chunk_size);
        chunk_map.insert(std::make_pair(chunk, i));
    }
    for (int i=0; i<input_str.length(); i=i+chunk_size) {
        string chunk = input_str.substr(i,chunk_size);
        unordered_map<string,int>::const_iterator it = chunk_map.find (chunk);
        if (it != chunk_map.end()) {
            string chunk_index = to_string(it->second);
            size_t found = res.find(chunk);
            if (found == -1) {
                res += chunk_index;
                res += chunk;
            }
            else res += chunk_index;
        }
    }
    return res;
}

std::string chunkFromIndex(std::string dedupStr, int index, int chunk_size) {
    size_t found = dedupStr.find(to_string(index));
    string chunk = "";
    if (found != -1) {
        chunk = dedupStr.substr(found+1, chunk_size);
    }
    return chunk;
}

std::string redup(std::string deduplicated_str, int chunk_size) {
    int i=0;
    string res = "";
    while(i<deduplicated_str.length()) {
        string chari = "";
        chari += deduplicated_str[i];
        string chunk = chunkFromIndex(deduplicated_str, atoi(chari.c_str()), chunk_size);
        res += chunk;
        if (chunk == deduplicated_str.substr(i+1, chunk_size)) {
            i = i+chunk_size+1;
        }
        else i++;
    }
    return res;
}

int main() {
    string s = "abcdefghabcd";
    string dedp = dedup(s, 4);
    cout << dedp << endl;

    string redp = redup(dedp, 4);
    cout << redp << endl;

    string t = "(123) 456-7890";
    string r1 = find_phone_number(t);
    cout << r1 << endl;

    string t1 = "xxx567-343-2312";
    string r2 = find_phone_number(t1);
    cout << r2 << endl;
    /*vector<int> p;
    p.push_back(-3);
    p.push_back(-2);
    p.push_back(-1);
    p.push_back(5);
    p.push_back(6);
    p.push_back(7);
    p.push_back(9);
    p.push_back(11);
    p.push_back(12);
    p.push_back(13);
    p.push_back(15);
    p.push_back(16);
    string res = solution(p);
    cout << res << endl;*/
    return 0;
}