// YandexTasks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/* #include <iostream>

int main()
{
    std::cout << "Hello World!\n";
} */ 


/* #include <iostream>
#include <vector>
using namespace std;

int main() {
    const vector<int> xs = { 1, 2, 1, 1, 5 };
    cout << count(xs.begin(), xs.end(), 1) << endl; // 3
} */ 


/* #include <iostream>
#include <Vector>
using namespace std;

int main() {
    const vector<string> escapees = {"cat"s, "dog"s, "parrot"s, "cat"s, "rat"s, "parrot"s, "cat"s, "dog"s};
    cout << count(escapees.begin(), escapees.end(), "parrot"s); 
} */ 


/* #include <iostream>
#include <vector>
using namespace std;

int main() {
    const vector<string> escapees = { "cat"s, "dog"s, "parrot"s, "cat"s, "rat"s, "parrot"s, "cat"s, "dog"s };
    cout << count(escapees.begin(), escapees.end(),"parrot"s) << '\n';
} */


/* #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsPositive(int x) {
    return x > 0;
}

int main() {
    const vector<int> xs = { 1, 2, 1, 1, 5 };
    int num_positive = count_if(xs.begin(), xs.end(), IsPositive);
    cout << num_positive << '\n';
} */


/* #include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPositive(int x) {
    return x > 0;
}

int main() {
    const vector<int> xs = { 1,2,1,1,5 };
    int num_positive = count_if(xs.begin(), xs.end(), isPositive);
    cout << num_positive << '\n';
} */


// Ранее вы реализовали функцию PrintWorryCount. Перепишите её, используя count.

/* #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isTrue(bool x) {
    return x == true;
}

void PrintWorryCount(const vector<bool>& is_nervous) {
    // подсчитываем количество элементов в векторе is_nervous, равных true
    // int worry_count = 0;
   // for (bool status : is_nervous) {
    //    if (status) { ++worry_count; }
    //}  
    int worry_count = count_if(is_nervous.begin(), is_nervous.end(), isTrue);
    cout << worry_count << endl;
}

int main() {
    // не меняйте содержимое функции main
    PrintWorryCount({ true, true, false, true });
    return 0;
} */ 



// Напишите функцию, которая принимает вектор строк и возвращает число строк, 
// начинающихся на большую или маленькую английскую букву “a”.
/* #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isA(string s) {
    return (s[0] == 'a' || s[0] == 'A');
}

int CountStartsWithA(const vector<string>& xs) {
    // посчитайте число строк, начинающихся на букву A
    int count_starts_with_a = count_if(xs.begin(), xs.end(), isA);
    return count_starts_with_a;
}

int main() {
    // не меняйте тело main
    cout << CountStartsWithA({ "And"s, "another"s, "one"s, "gone"s, "another"s, "one"s "bites"s, "the"s, "dust"s });
    return 0;
} */



//Считайте количество людей, имя и возраст каждого. Выведите все имена с новой строки по старшинству — от старых к молодым.

/* #include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int count;
    cin >> count;
    vector<pair<int, string>>names(count);
    for (int i = 0; i < count; ++i) {
        string name;
        int age;
        cin >> name >> age;
        // сохраните в вектор пар
        names[i].first = age;
        names[i].second = name;
    }
    sort(names.begin(), names.end());
    reverse(names.begin(), names.end());
    for (int i = 0; i < count; i++)
        cout << names[i].second << '\n';
    // выведите только имена в порядке убывания возраста
    // Jack
    // John
    // ...
} */



// Напишите функцию, которая принимает на вход вектор времени ответа и вычисляет медиану этого вектора. 
// Вектор может быть неотсортированным.

/* #include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

pair<bool, double> CalcMedian(vector<double> samples) {
    // верните {true, медиана}, если она существует,
    // то есть вектор непустой,
    // иначе - {false, 0}
    // обратите внимание - вектор принимаем по значению,
    // так как его придётся немного подпортить, чтобы вернуть ответ
    sort(samples.begin(), samples.end());
    int n = samples.size();
    double m=0.0;
    if (n % 2 == 0) { m = (samples[n / 2 - 1] + samples[n / 2]) / 2; }
    else m = samples[n/2];
    if (m != 0) return { true,m };
    else return { false,0 };
}

int main() {
    int size;
    cin >> size;

    vector<double> samples;
    for (int i = 0; i < size; ++i) {
        double sample;
        cin >> sample;
        samples.push_back(sample);
    }

    pair<bool, double> result = CalcMedian(samples);
    if (result.first) cout << result.second << endl;
    else cout << "Empty vector"s << endl;
} */


/* #include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> values;
    for (int i = 0; i < size; ++i) {
        int value;
        cin >> value;
        values.push_back(value);
    }

    int sum = accumulate(values.begin(), values.end(), 0);
    cout << sum << endl;
} */ 


/* #include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    int size;
    cin >> size;
    vector<int> values;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        values.push_back(x);
    }
    int sum = accumulate(values.begin(), values.end(), 0);
    cout << sum << '\n';
} */ 


// Вычислите среднее арифметическое вектора чисел. Считайте, что среднее арифметическое пустого массива равно нулю.
/* #include <iostream>
#include <vector>
#include <numeric>
using namespace std;

double Average(const vector<int>& xs) {
    // посчитайте среднее арифметическое: поделите сумму на размер
    // суммирование начните с 0.0 - тогда результат выражения будет вещественным числом
    double sum = accumulate(xs.begin(), xs.end(),0);
    int n = xs.size();
    if (n == 0) return 0;
    else return (double)(sum / n);
}

int main() {
    // не меняйте код main
    cout << Average({ 1, 2, 2 }) << endl;
    return 0;
} */


//Напишите функцию, которая принимает строку-запрос и множество стоп-слов и возвращает новую строку. 
// В новой строке после запроса идут стоп-слова через пробел, перед каждым стоит дефис. 
// Передайте в accumulate четвёртым аргументом функцию, сворачивающую множество стоп-слов в «хвост» нужного формата.

/* #include <iostream>
#include <numeric>
#include <set>
using namespace std;

string PairFold(string s) {
    s = ('-' + s);
    return s;
}

string AddStopWords(const string& query, const set<string>& stop_words) {
    string s = accumulate(query.begin(), query.end(), " ", PairFold);
    string a = accumulate(stop_words.begin(), stop_words.end()," ",PairFold);
    string g = s + a;
    return g;
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    set<string>se;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        se.insert(x);
    }
    string ans = AddStopWords(s, se);
    cout << ans << '\n';
} */





/* #include <iostream>
#include <set>
using namespace std;

int main() {
    const set<string> menagerie = { "cat"s, "dog"s, "rat"s };
    cout << menagerie.count("cat"s) << endl;
    cout << count(menagerie.begin(), menagerie.end(), "cat"s) << endl;
} */


/* #include <iostream>
#include <set>
using namespace std;

int main() {
    const set<string> menagerie = { "cat"s, "dog"s, "rat"s };
    cout << menagerie.count("cat"s) << '\n';
    cout << count(menagerie.begin(), menagerie.end(), "cat"s) << '\n';
} */


/* #include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <vector>
using namespace std;
const int SAMPLE_COUNT = 5;

vector<int> CountNamesLong(const set<string>& storage, const vector<string>& candidates) {
    vector<int> output;
    for (auto& name : candidates) {
        output.push_back(count(storage.begin(), storage.end(), name));
    }
    return output;
}

vector<int> CountNames(const set<string>& storage, const vector<string>& candidates) {
    vector<int> output;
    for (auto& name: candidates) {
        if (storage.count(name)) output.push_back(1);
        else output.push_back(1);
    }
    return output;
}

int main() {
    set<string> s;
    vector<string> v;
    string stra = ""s;
    string strb = ""s;

    for (int j = 0; j < 10000; ++j) {
        s.insert(stra);
        stra += "a"s;
        if (j % 2 == 0) {
            v.push_back(strb);
            strb += "b"s;
        }
        else {
            v.push_back(stra);
        }
    }
    //cout << "Testing slow version" << endl;
    for (int i = 0; i < SAMPLE_COUNT; ++i) {
        auto begin = chrono::steady_clock::now();
        CountNames(s, v);
        auto end = chrono::steady_clock::now();
        cout << "Time difference Long = "s << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[µs]"s << endl;
    }
} */ 


/* #include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result;
    cin >> result;
    ReadLine();
    return result;
}

vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        }
        else {
            word += c;
        }
    }
    words.push_back(word);

    return words;
}

set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

void AddDocument(map<string, set<int>>& word_to_documents,
    const set<string>& stop_words,
    int document_id,
    const string& document) {
    for (const string& word : SplitIntoWordsNoStop(document, stop_words)) {
        word_to_documents[word].insert(document_id);
    }
}

// For each document returns its relevance and id
vector<pair<int, int>> FindAllDocuments(
    const map<string, set<int>>& word_to_documents,
    const set<string>& stop_words,
    const string& query) {
    const vector<string> query_words = SplitIntoWordsNoStop(query, stop_words);
    map<int, int> document_to_relevance;
    for (const string& word : query_words) {
        if (word_to_documents.count(word) == 0) {
            continue;
        }
        for (const int document_id : word_to_documents.at(word)) {
            ++document_to_relevance[document_id];
        }
    }

    vector<pair<int, int>> found_documents;
    for (auto [document_id, relevance] : document_to_relevance) {
        found_documents.push_back({ relevance, document_id });
    }

    return found_documents;
}

// For each document returns its id and relevance
vector<pair<int, int>> FindTopDocuments(
    const map<string, set<int>>& word_to_documents,
    const set<string>& stop_words,
    const string& query) {
    auto matched_documents = FindAllDocuments(word_to_documents, stop_words, query);

    sort(execution::par,matched_documents.begin(), matched_documents.end());
    reverse(matched_documents.begin(), matched_documents.end());
    if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
        matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
    }
    for (auto& matched_document : matched_documents) {
        swap(matched_document.first, matched_document.second);
    }
    return matched_documents;
}


int main() {
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read documents
    map<string, set<int>> word_to_documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(word_to_documents, stop_words, document_id, ReadLine());
    }

    const string query = ReadLine();
    for (auto [document_id, relevance] : FindTopDocuments(word_to_documents, stop_words, query)) {
        cout << "{ document_id = "s << document_id << ", relevance = "s << relevance << " }"s << endl;
    }
} */


/* #include <iostream>
#include <chrono> //эта библиотека отвечает за концепты, связанные со временем
#include <vector>
#include <numeric>
#include <execution>
using namespace std;

int main(){
    std::vector<int> v(200'000'001, 1);

    const auto startTime = chrono::high_resolution_clock::now();
    int result = std::accumulate(v.begin(), v.end(), 0);
    const auto endTime = chrono::high_resolution_clock::now();
    cout << "std::accumulate execution time: "s << chrono::duration_cast<chrono::duration<int, milli>>(endTime - startTime).count() << " ms."s << endl;

    const auto startTimeReduce = chrono::high_resolution_clock::now();
    int resultReduce = std::reduce(execution::par, v.begin(), v.end(), 0);
    const auto endTimeReduce = chrono::high_resolution_clock::now();
    cout << "std::reduce execution time: "s << chrono::duration_cast<chrono::duration<int, milli>>(endTimeReduce - startTimeReduce).count() << " ms."s << endl;
} */



/* #include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

template <typename Term>
map<Term, int> ComputeTermFreqs(const vector<Term>& terms) {
    map<Term, int> term_freqs;
    for (const Term& term : terms) {
        ++term_freqs[term];
    }
    return term_freqs;
}

pair<string, int> FindMaxFreqAnimal(const vector<pair<string, int>>& animals) {
    // верните животного с максимальной частотой
    int cnt = 0;
    string name;
    map<string, int> v;
    for (const auto& it : animals) {
        v[it.first]++;
        if (v[it.first] > cnt) {
            cnt = v[it.first];
            name = it.first;
        }
    }
    pair<string, int> ans;
    for (const auto& it : animals) {
        if (it.first == name) {
            ans = it; break;
        }
    }
    return ans;
}

int main() {
    const vector<pair<string, int>> animals = {
        {"Murka"s, 5},
        {"Belka"s, 6},
        {"Murka"s, 7},
        {"Murka"s, 5},
        {"Belka"s, 6},
    };
    const pair<string, int> max_freq_animal = FindMaxFreqAnimal(animals);
    cout << max_freq_animal.first << " "s
        << max_freq_animal.second << endl;
} */ 

/* #include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& out, const vector<string>& container) {
    for (const string& element : container) {
        out << element << " "s;
    }
    return out;
}

int main() {
    const vector<string> cats = { "Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s };
    cout << cats << endl;
} */ 


/* #include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& out, const vector<string>& container) {
    for (const string& element : container)
        out << element << " "s;
    return out;
}

int main() {
    const vector<string> cats = { "Lucy", "Kate", "Puxus", "Flower" };
    cout << cats << '\n';
} */ 

//Доработайте оператор вывода вектора в поток, чтобы он работал с любым вектором — при условии, 
// что сами его элементы можно выводить оператором <<. 
// Так, для вектора целых чисел код из тренажёра должен выводить 10 5 2 12 .

/* #include <iostream>
#include <vector>
using namespace std;

template<typename Element>
ostream& operator<<(ostream& out, const vector<Element>& v) {
    for (auto it : v)
        out << it << " ";
    return out;
}

int main() {
    const vector<int> ages = { 10, 5, 2, 12 };
    cout << ages << endl;
} */

// Вы могли заметить лишний пробел, который выводится после последнего элемента. 
// Избавьтесь от него и замените пробел на запятую с пробелом. 
// Код из предыдущей задачи теперь должен выводить 10, 5, 2, 12.

/* #include <iostream>
#include <vector>
using namespace std;

template<typename Element>
ostream& operator<<(ostream& out, const vector<Element>& v) {
    for (int i = 0; i < v.size(); i++) {
        out << v[i];
        if (i != v.size() - 1) out << ", ";
    }
    return out;
}

int main() {
    const vector<int> ages = { 10, 5, 2, 12 };
    cout << ages << endl;
} */


// Научите функцию вывода работать не только с векторами, но и со множествами.
/* #include <iostream>
#include <vector>
#include <set>
using namespace std;

template<typename Element>
ostream& operator<<(ostream& out, const vector<Element>& v) {
    for (int i = 0; i < v.size(); i++) {
        out << v[i];
        if (i != v.size() - 1) out << ", ";
    }
    return out;
}   

template<typename Element>
ostream& operator<<(ostream& out, set<Element>& s) {
    for(auto it: s) 
        out << s << " ";
    return out;
}

int main() {
    set<string> cats = { "Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s };
    cout << cats << endl;
} */ 
















