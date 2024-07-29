#include <iostream>
#include <vector>
#include <memory>


template<typename T>
using Array = std::vector<T>;

template<typename T>
using Matrix = Array<Array<T>>;


template<typename T>
std::unique_ptr<Matrix<T>> _c(std::shared_ptr<Matrix<T>> a, std::shared_ptr<Matrix<T>> b);


template<typename T>
std::unique_ptr<Matrix<T>> identity(uint size_x, uint size_y);

template<typename T>
std::unique_ptr<Matrix<T>> transpose(std::shared_ptr<Matrix<T>> input);

template<typename T>
std::unique_ptr<Matrix<T>> dot(std::shared_ptr<Matrix<T>> a, std::shared_ptr<Matrix<T>> b);

template<typename T>
std::unique_ptr<Matrix<T>> mult(std::shared_ptr<Matrix<T>> a, std::shared_ptr<Matrix<T>> b);

template<typename T>
std::unique_ptr<Matrix<T>> inverse(std::shared_ptr<Matrix<T>> matrix);

template<typename T>
std::unique_ptr<Array<T>> gauss(std::shared_ptr<Matrix<T>> matrix, std::shared_ptr<Array<T>> b);

template<typename T>
std::unique_ptr<Array<T>> cholesky(std::shared_ptr<Matrix<T>> A, std::shared_ptr<Matrix<T>> b);

template<typename T>
std::unique_ptr<Array<T>> decomposition(std::shared_ptr<Matrix<T>> U, std::shared_ptr<Matrix<T>> b);
