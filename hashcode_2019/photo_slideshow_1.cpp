#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <unordered_set>

#define DEBUG 0

using namespace std;

class Photo{
public:
    char ori;
    unordered_set<long long int> tags;
    bool isMerged;
    pair<int, int> ind;

    Photo(char _ori, unordered_set<long long int> _tags, int _fInd, int _sInd = 0) : ori(_ori), tags(_tags), isMerged(false), ind(_fInd, _sInd) {}

    void print() {
        cout << "P " << ori << " " << tags.size() << " ";
        for (long long int t : tags) {
            cout << t << " ";
        }
        cout << "\n";
    }

    void print_sol(ofstream* out) {
        if (isMerged) {
            *out << ind.first << " " << ind.second << "\n";
        } else {
            *out << ind.first << "\n";
        }
    }

    int calScore(Photo b) {
        int score_ab = 0;
        int score_a = 0;
        int score_b = 0;

        for (long long int t : tags) {
            if (b.tags.count(t)) {
                score_ab++;
            }
        }

        score_a = tags.size() - score_ab;
        score_b = b.tags.size() - score_ab;
        return min(score_ab, min(score_a, score_b));
    }

    Photo* mergePics(Photo b) {
        assert(!b.isMerged && !isMerged);
        assert(b.ori == 'V' && ori == 'V');

        unordered_set<long long int> new_tags(tags);
        new_tags.insert(b.tags.begin(), b.tags.end());

        Photo* newP = new Photo('V', new_tags, ind.first, b.ind.first);
        newP->isMerged = true;

        return newP;
    }

};

int n;
vector<Photo> pics_v, pics_h;

long long int toLL(string s) {
    long long int out = 0;
    for(int i = 0; i < s.size(); i++) {
        out *= 36;
        if(s[i] >= '0' && s[i] <= '9') {
            out += s[i] - '0';
        } else {
            out += s[i] - 'a';
        }
    }
    return out;
}

int main(int argc, char *argv[]){
    assert(argc == 2);

    // setup the program
    srand(time(NULL));

    // read input
    cin >> n;

    unordered_set<long long int> in_tags;
    for(int i = 0; i < n; i++){
        int m;
        char o;
        in_tags.clear();
        cin >> o >> m;

        for(int j = 0; j < m; j++) {
            string s;
            cin >> s;
            in_tags.insert(toLL(s));
        }
        assert(o == 'V' || o == 'H');
        if (o == 'V') {
            pics_v.push_back(Photo(o, in_tags, i));
        } else {
            pics_h.push_back(Photo(o, in_tags, i));
        }
    }
    cout << "Done input\n";

    // test print
    if (DEBUG) {
        for(Photo p : pics_v){
            p.print();
        }
    }

    // merge vertical pics
    vector<Photo*> pSpace;
    for(int i = 0; i < pics_h.size(); i++) {
        pSpace.push_back(&pics_h[i]);
    }
    for(int i = 1; i < pics_v.size(); i += 2) {
        pSpace.push_back(pics_v[i-1].mergePics(pics_v[i]));
    }
    cout << "Done merge\n";

    vector<Photo*> slide;

    // random the first pic
    int cur_i = rand() % pSpace.size();

    if(DEBUG) cout << "Rand " << cur_i << " " << pSpace.size() << "\n";

    // linear add : super bad sol
    /* for(int i = 0; i < pSpace.size(); i++){
        slide.push_back(pSpace[i]);
    } */

    // add it to slide
    while(pSpace.size() > 1){

        if (DEBUG){
            cout << "Add " << cur_i << "\n";
        }

        Photo* tmpPhoto = pSpace[cur_i];

        slide.push_back(pSpace[cur_i]);
        pSpace[cur_i] = pSpace.back();
        pSpace.pop_back();

        // find next max
        int mx = -1;
        int mx_ind = -1;

        for(int j = 0; j < pSpace.size() && j < 300; j++){
            int cs = tmpPhoto->calScore(*pSpace[j]);
            if(cs > mx) {
                mx = cs;
                mx_ind = j;
            }
        }

        if (pSpace.size() % 100 == 0){
            cout << "Match " << pSpace.size() << "\n";
        }

        cur_i = mx_ind;
    }

    slide.push_back(pSpace[cur_i]);

    //print output to file
    ofstream outfile;
    outfile.open (argv[1]);
    outfile << slide.size() << "\n";
    for(Photo* s : slide) {
        s->print_sol(&outfile);
    }
    outfile.close();

    return 0;
}
