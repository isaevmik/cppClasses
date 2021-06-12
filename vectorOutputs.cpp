// Вывод одномерного вектора
template <typename T>
void D1out(vector<T> line) {
    for (const auto& elem : line) {
        cout << elem << ' ';
    }
    cout << endl;
}

// Вывод матрицы (двумерного вектора)
template <typename T>
void D2out(vector<vector<T>> matrix) {
    size_t counter = 0;
    for (const auto& line : matrix) {
        cout << "Line " << counter << endl << "\t";
        for (const auto& column : line) {
            cout << column << ' ';
        }
        cout << endl;
        ++counter;
    }
    cout << endl;
}
