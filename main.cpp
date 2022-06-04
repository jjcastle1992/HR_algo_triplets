#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'compareTriplets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    //Vector a contains Alice's scores in each of the 3 criteria [0,2]
    //Vector b contains Bob's scores in each of the 3 criteria [0,2]
    int indexMatchedInputVectorSize = a.size();
    vector<int> scores;
    int aliceScore = 0;
    int bobScore = 0;

    //create a count-controlled loop that goes through each of the 3 indices, comparing the values of a[n] and b[n].
    for (int i = 0; i < indexMatchedInputVectorSize; i++) {
        int aliceTemp = a[i];
        int bobTemp = b[i];

        // the greater value gets assigned a point. If the values ==, then no points are assigned. (if, else if, else?)
        if (aliceTemp > bobTemp) {
            aliceScore++;
        }
        else if (bobTemp > aliceTemp) {
            bobScore++;
        }
        else { //if scores are ==, then do nothing.
        }
    }

    //Should end up with a new 2 element vector with the scores of Alice in the 0th index and Bob in the 1st.
    scores.push_back(aliceScore);
    scores.push_back(bobScore);
    //Return the index back to the caller.
    return scores;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(3);

    for (int i = 0; i < 3; i++) {
        int a_item = stoi(a_temp[i]);
        if (a_item >= 1 && a_item <= 100) {
            a[i] = a_item;
        }
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split(rtrim(b_temp_temp));

    vector<int> b(3);

    for (int i = 0; i < 3; i++) {
        int b_item = stoi(b_temp[i]);
        if (b_item >= 1 && b_item <= 100) {
            b[i] = b_item;
        }
    }

    vector<int> result = compareTriplets(a, b);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
