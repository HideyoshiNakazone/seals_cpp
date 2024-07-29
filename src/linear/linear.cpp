#include "linear.hpp"


template<typename T>
std::unique_ptr<Matrix<T>> _c(std::shared_ptr<Matrix<T>> a, std::shared_ptr<Matrix<T>> b) {
    if (a->size() != b->size()) {
        return nullptr;
    }
    
    auto c = std::make_unique<Matrix<T>>();

    for (int i = 0; i < a->size(); i++) {
        auto row = Array<T>();
        for (int j = 0; j < a->at(0).size(); j++) {
            row.push_back(a->at(i).at(j));
        }
        for (int j = 0; j < b->at(0).size(); j++) {
            row.push_back(b->at(i).at(j));
        }
        c->push_back(row);
    }

    return c;
}

// template<typename T>
// std::unique_ptr<Matrix<T>> identity(uint size_x, uint size_y) {
//     auto a = make_matrix<T>(size_x, size_y);

//     for (int i = 0; i < size_x; i++) {
//         for (int j = 0; j < size_y; j++) {
//             if (i == j) {
//                 a->at(i).at(j) = 1;
//             } else {
//                 a->at(i).at(j) = 0;
//             }
//         }
//     }

//     return a;
// }

// template<typename T>
// std::unique_ptr<Matrix<T>> transpose(std::shared_ptr<Matrix<T>> input) {
//     auto transposed = make_matrix<T>(input->at(0).size(), input->size());

//     for (int i = 0; i < transposed->size(); i++) {
//         for (int j = 0; j < transposed->at(0).size(); j++) {
//             transposed->at(i).at(j) = input->at(j).at(i);
//         }
//     }

//     return transposed;   
// }

// template<typename T>    
// std::unique_ptr<Matrix<T>> dot(std::shared_ptr<Matrix<T>> a, std::shared_ptr<Matrix<T>> b) {
//     auto c = make_matrix<T>(a->size(), b->at(0).size());

//     for (int i = 0; i < a->size(); i++) {
//         for (int j = 0; j < b->at(0).size(); j++) {
//             c->at(i).at(j) = 0;
//             for (int k = 0; k < a->at(0).size(); k++) {
//                 c->at(i).at(j) += a->at(i).at(k) * b->at(k).at(j);
//             }
//         }
//     }

//     return c;
// }


// template<typename T>
// std::unique_ptr<Matrix<T>> mult(std::shared_ptr<Matrix<T>> a, std::shared_ptr<Matrix<T>> b) {
//     auto c = make_matrix<T>(a->size(), b->at(0).size());

//     for (int i = 0; i < a->size(); i++) {
//         for (int j = 0; j < b->at(0).size(); j++) {
//             c->at(i).at(j) = a->at(i).at(j) * b->at(i).at(j);
//         }
//     }

//     return c;
// }


// template<typename T>
// std::unique_ptr<Matrix<T>> inverse(std::shared_ptr<Matrix<T>> matrix) {
//     if (matrix->size() != matrix->at(0).size()) {
//         return nullptr;
//     }

//     uint size = matrix->size();

//     auto extended = _c(matrix, identity<T>(size, size));

//     uint i = 0;
//     while (i < size) {
//         uint j = i;
//         while (j < size && extended->at(j).at(i) == 0) {
//             j++;
//         }

//         if (j == size) {
//             return nullptr;
//         }

//         if (i != j) {
//             for (uint k = 0; k < 2 * size; k++) {
//                 std::swap(extended->at(i).at(k), extended->at(j).at(k));
//             }
//         }

//         for (uint j = 0; j < size; j++) {
//             if (j != i) {
//                 T ratio = extended->at(j).at(i) / extended->at(i).at(i);
//                 for (uint k = 0; k < 2 * size; k++) {
//                     extended->at(j).at(k) -= ratio * extended->at(i).at(k);
//                 }
//             }
//         }

//         i++;
//     }

//     auto inversed = make_matrix<T>(size, size);
    
//     for (uint i = 0; i < size; i++) {
//         for (uint j = 0; j < size; j++) {
//             inversed->at(i).at(j) = extended->at(i).at(size + j);
//         }
//     }
    
//     return inversed;
// }