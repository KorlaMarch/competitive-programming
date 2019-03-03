#include <bits/stdc++.h>

#define DEBUG 0

using namespace std;

class Photo{
public:
    char ori;
    unordered_set<string> tags;
    bool isMerged;
    pair<int, int> ind;

    Photo(char _ori, unordered_set<string> _tags, int _fInd, int _sInd = 0) : ori(_ori), tags(_tags), isMerged(false), ind(_fInd, _sInd) {}

    void print() {
        cout << "P " << ori << " " << tags.size() << " ";
        for (string t : tags) {
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

        for (string t : tags) {
            if (b.tags.count(t)) {
                score_ab++;
            } else {
                score_a++;
            }
        }

        for (string t : b.tags) {
            if (!tags.count(t)) {
                score_b++;
            }
        }

        return min(score_ab, min(score_a, score_b));
    }

    Photo* mergePics(Photo b) {
        assert(!b.isMerged && !isMerged);
        assert(b.ori == 'V' && ori == 'V');

        unordered_set<string> new_tags(tags);
        new_tags.insert(b.tags.begin(), b.tags.end());

        Photo* newP = new Photo('V', new_tags, ind.first, b.ind.first);
        newP->isMerged = true;

        return newP;
    }

};

int n;
vector<Photo> pics_v, pics_h;

int main(){
    // setup the program
    srand(time(NULL));

    // read input
    cin >> n;

    unordered_set<string> in_tags, all_words;
    for(int i = 0; i < n; i++){
        int m;
        char o;
        in_tags.clear();
        cin >> o >> m;

        for(int j = 0; j < m; j++) {
            string s;
            cin >> s;
            all_words.insert(s);
            in_tags.insert(s);
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

    /*
    //inti array
    bool isUsed[pSpace.size()];
    for (int i = 0; i < pSpace.size(); i++) {
        isUsed[i] = false;
    }

    // random the first pic
    int cur_i = rand() % pSpace.size();

    if(DEBUG) cout << "Rand " << cur_i << " " << pSpace.size() << "\n";

    // add it to slide
    for(int i = 1; i < pSpace.size(); i++){
        isUsed[cur_i] = true;
        if (DEBUG){
            cout << "Add " << cur_i << "\n";
        }
        slide.push_back(pSpace[cur_i]);

        // find next max
        int mx = -1;
        int mx_ind = -1;

        for(int j = 0; j < pSpace.size(); j++){
            if (!isUsed[j]) {
                int cs = pSpace[cur_i]->calScore(*pSpace[j]);
                if(cs > mx) {
                    mx = cs;
                    mx_ind = j;
                }
            }
        }

        if (i % 100 == 0){
            cout << "Match " << i << "/" << pSpace.size() << "\n";
        }
        cur_i = mx_ind;
    }

    slide.push_back(pSpace[cur_i]);
    */
    vector<Photo*> slide;
    vector<string> nwstring, all_words_vec;
    vector<int> v1, v2;
    bool isUsed[pSpace.size()];
    memset(isUsed, 0, pSpace.size());
    for(string t : all_words)
        all_words_vec.push_back(t);
    int rd = 100;
    int keeword = 6;
    int i, j, cnt;
    for(int runrun = 0; runrun < rd; runrun++)
    {
        if((runrun+1)*keeword - 1 > all_words_vec.size())
            break;
        nwstring.clear();
        v1.clear();
        v2.clear();
        for(i = runrun*keeword; i<(runrun+1)*keeword; i++)
            nwstring.push_back(all_words_vec[i]);
        for(i = 0; i < pSpace.size(); i++)
        {
            if(isUsed[i] == true)
                continue;
            cnt = 0;
            for(j = 0; j < nwstring.size(); j++)
                cnt += pSpace[i]->tags.count(nwstring[j]);
            if(cnt == keeword)
                v1.push_back(i);
            if(cnt == keeword/2)
                v2.push_back(i);
        }
        while(v1.size()!=0 && v1.size()!=0)
        {
            slide.push_back(pSpace[v1.back()]);
            slide.push_back(pSpace[v2.back()]);
            isUsed[v1.back()] = true;
            isUsed[v2.back()] = true;
            v1.pop_back();
            v2.pop_back();
        }
    }
    for(i = 0; i < pSpace.size(); i++)
        if(isUsed[i] == false)
            slide.push_back(pSpace[i]);
    //print output to file
    ofstream outfile;
    outfile.open ("output.txt");
    outfile << slide.size() << "\n";
    for(Photo* s : slide) {
        s->print_sol(&outfile);
    }
    outfile.close();

    return 0;
}