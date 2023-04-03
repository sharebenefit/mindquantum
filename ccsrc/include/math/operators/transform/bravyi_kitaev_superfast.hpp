//   Copyright 2020 <Huawei Technologies Co., Ltd>
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#ifndef BRAVYI_KITAEV_SUPERFAST_TRANSFORM_HPP
#define BRAVYI_KITAEV_SUPERFAST_TRANSFORM_HPP

#include <map>
#include <set>
#include <vector>

#include "math/operators/fermion_operator_view.hpp"
#include "math/operators/qubit_operator_view.hpp"
namespace operators::transform {
using qubit_op_t = qubit::QubitOperator;
using fermion_op_t = fermion::FermionOperator;
using edge_matrix_t = std::vector<std::vector<int>>;
using edge_enum_t = std::map<std::pair<int, int>, int>;
using edge_set_t = std::set<std::pair<int, int>>;

//! Bravyi kitaev superfast transform that transform a Fermion operator to qubit operator.
edge_matrix_t get_edge_matrix(const fermion_op_t& ops);

edge_enum_t enumerate_edges(const edge_matrix_t& edge_matrix);

qubit_op_t get_b(int i, const edge_matrix_t& edge_matrix, edge_enum_t& edge_enum);

qubit_op_t get_a(int i, int j, const edge_matrix_t& edge_matrix, edge_enum_t& edge_enum);

qubit_op_t transformed_number_operator(int i, const edge_matrix_t& edge_matrix, edge_enum_t& edge_enum);

qubit_op_t transformed_excitation_operator(int i, int j, const edge_matrix_t& edge_matrix, edge_enum_t& edge_enum);

qubit_op_t transformed_exchange_operator(int i, int j, const edge_matrix_t& edge_matrix, edge_enum_t& edge_enum);

qubit_op_t transformed_number_excitation_operator(int i, int j, int k, const edge_matrix_t& edge_matrix,
                                                  edge_enum_t& edge_enum);

qubit_op_t transformed_double_excitation_operator(int i, int j, int k, int l, const edge_matrix_t& edge_matrix,
                                                  edge_enum_t& edge_enum);

qubit_op_t bravyi_kitaev_superfast(const fermion_op_t& ops);
}  // namespace operators::transform

#endif
