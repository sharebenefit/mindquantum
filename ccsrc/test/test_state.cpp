#include <iostream>
#include <complex>
#include <functional>

#include "simulator/densitymatrix/densitymatrix_state.hpp"
#include "simulator/densitymatrix/detail/cpu_densitymatrix_policy.hpp"
#include "gate/basic_gate.h"
#include "gate/gates.h"

using namespace mindquantum::sim::densitymatrix::detail;
using namespace mindquantum;

int main() {
    auto x = XGate<double>;
    x.obj_qubits_ = {1};
    x.ctrl_qubits_ = {0};
    std::shared_ptr<BasicGate<double>> p_x = std::make_shared<BasicGate<double>>(x);

    auto h = HGate<double>;
    h.obj_qubits_ = {0};
    h.ctrl_qubits_ = {};
    std::shared_ptr<BasicGate<double>> p_h = std::make_shared<BasicGate<double>>(h);

    auto h2 = HGate<double>;
    h2.obj_qubits_ = {1};
    h2.ctrl_qubits_ = {};
    std::shared_ptr<BasicGate<double>> p_h2 = std::make_shared<BasicGate<double>>(h2);

    auto measure = GetMeasureGate<double>(std::string("q0"));
    measure.obj_qubits_ = {0};
    std::shared_ptr<BasicGate<double>> p_measure = std::make_shared<BasicGate<double>>(measure);

    
    auto dm = DensityMatrixState<CPUDensityMatrixPolicyBase>(2, 3);
    dm.ApplyGate(p_h);
    dm.ApplyGate(p_x);
    // dm.ApplyGate(p_x);
    dm.ApplyMeasure(p_measure);
    dm.DisplayQS();
}