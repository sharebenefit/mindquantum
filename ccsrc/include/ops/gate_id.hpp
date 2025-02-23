//   Copyright 2023 <Huawei Technologies Co., Ltd>
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

#ifndef MQ_GATE_ID
#define MQ_GATE_ID

#include <fmt/format.h>
#include <nlohmann/json.hpp>

namespace mindquantum {
enum class GateID : uint8_t {
    null,
    I,      //
    X,      //
    Y,      //
    Z,      //
    RX,     //
    RY,     //
    RZ,     //
    Rxx,    //
    Ryy,    //
    Rzz,    //
    Rxy,    //
    Rxz,    //
    Ryz,    //
    H,      //
    SWAP,   //
    ISWAP,  //
    T,      //
    S,      //
    Tdag,   //
    Sdag,   //
    CNOT,   //
    CZ,     //
    GP,     //
    PS,     //
    U3,     //
    FSim,   //
    M,      //
    PL,     // Pauli channel
    DEP,    // depolarizing channel
    AD,     // amplitude damping channel
    PD,     // phase damping channel
    KRAUS,
    CUSTOM,
    HOLDER,  // for extended gate id.
};

// NOLINTNEXTLINE(*avoid-c-arrays,readability-identifier-length)
NLOHMANN_JSON_SERIALIZE_ENUM(GateID, {{GateID::I, "I"},         {GateID::X, "X"},         {GateID::Y, "Y"},
                                      {GateID::Z, "Z"},         {GateID::RX, "RX"},       {GateID::RY, "RY"},
                                      {GateID::RZ, "RZ"},       {GateID::Rxx, "Rxx"},     {GateID::Ryy, "Ryy"},
                                      {GateID::Rzz, "Rzz"},     {GateID::Rxy, "Rxy"},     {GateID::Rxz, "Rxz"},
                                      {GateID::Ryz, "Ryz"},     {GateID::H, "H"},         {GateID::SWAP, "SWAP"},
                                      {GateID::ISWAP, "ISWAP"}, {GateID::T, "T"},         {GateID::S, "S"},
                                      {GateID::Tdag, "Tdag"},   {GateID::Sdag, "Sdag"},   {GateID::CNOT, "CNOT"},
                                      {GateID::CZ, "CZ"},       {GateID::GP, "GP"},       {GateID::PS, "PS"},
                                      {GateID::U3, "U3"},       {GateID::FSim, "FSim"},   {GateID::M, "M"},
                                      {GateID::PL, "PL"},       {GateID::DEP, "DEP"},     {GateID::AD, "AD"},
                                      {GateID::PD, "PD"},       {GateID::KRAUS, "KRAUS"}, {GateID::CUSTOM, "CUSTOM"}});
}  // namespace mindquantum
template <typename char_t>
struct fmt::formatter<mindquantum::GateID, char_t> {
    FMT_CONSTEXPR auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {  // NOLINT(runtime/references)
        return ctx.begin();
    }
    template <typename format_context_t>
    auto format_one(const mindquantum::GateID& value, format_context_t& ctx) const  // NOLINT(runtime/references)
        -> decltype(ctx.out()) {
        switch (value) {
            case mindquantum::GateID::GP:
                return fmt::format_to(ctx.out(), "GP");
            case mindquantum::GateID::PS:
                return fmt::format_to(ctx.out(), "PS");
            case mindquantum::GateID::U3:
                return fmt::format_to(ctx.out(), "U3");
            case mindquantum::GateID::FSim:
                return fmt::format_to(ctx.out(), "FSim");
            case mindquantum::GateID::M:
                return fmt::format_to(ctx.out(), "M");
            case mindquantum::GateID::CUSTOM:
                return fmt::format_to(ctx.out(), "CUSTOM");
            default:
                return fmt::format_to(ctx.out(), "Invalid <mindquantum::GateID>");
        }
    }
    template <typename format_context_t>
    auto format_two(const mindquantum::GateID& value, format_context_t& ctx) const  // NOLINT(runtime/references)
        -> decltype(ctx.out()) {
        switch (value) {
            case mindquantum::GateID::PL:
                return fmt::format_to(ctx.out(), "PL");
            case mindquantum::GateID::DEP:
                return fmt::format_to(ctx.out(), "DEP");
            case mindquantum::GateID::AD:
                return fmt::format_to(ctx.out(), "AD");
            case mindquantum::GateID::PD:
                return fmt::format_to(ctx.out(), "PD");
            case mindquantum::GateID::KRAUS:
                return fmt::format_to(ctx.out(), "KRAUS");
            default:
                return format_one(value, ctx);
        }
    }
    template <typename format_context_t>
    auto format_three(const mindquantum::GateID& value, format_context_t& ctx) const  // NOLINT(runtime/references)
        -> decltype(ctx.out()) {
        switch (value) {
            case mindquantum::GateID::RX:
                return fmt::format_to(ctx.out(), "RX");
            case mindquantum::GateID::RY:
                return fmt::format_to(ctx.out(), "RY");
            case mindquantum::GateID::RZ:
                return fmt::format_to(ctx.out(), "RZ");
            case mindquantum::GateID::Rxx:
                return fmt::format_to(ctx.out(), "Rxx");
            case mindquantum::GateID::Ryy:
                return fmt::format_to(ctx.out(), "Ryy");
            case mindquantum::GateID::Rzz:
                return fmt::format_to(ctx.out(), "Rzz");
            case mindquantum::GateID::Rxy:
                return fmt::format_to(ctx.out(), "Rxy");
            case mindquantum::GateID::Rxz:
                return fmt::format_to(ctx.out(), "Rxz");
            case mindquantum::GateID::Ryz:
                return fmt::format_to(ctx.out(), "Ryz");
            default:
                return format_two(value, ctx);
        }
    }
    template <typename format_context_t>
    auto format(const mindquantum::GateID& value, format_context_t& ctx) const  // NOLINT(runtime/references)
        -> decltype(ctx.out()) {
        switch (value) {
            case mindquantum::GateID::I:
                return fmt::format_to(ctx.out(), "I");
            case mindquantum::GateID::X:
                return fmt::format_to(ctx.out(), "X");
            case mindquantum::GateID::Y:
                return fmt::format_to(ctx.out(), "Y");
            case mindquantum::GateID::Z:
                return fmt::format_to(ctx.out(), "Z");
            case mindquantum::GateID::H:
                return fmt::format_to(ctx.out(), "H");
            case mindquantum::GateID::SWAP:
                return fmt::format_to(ctx.out(), "SWAP");
            case mindquantum::GateID::ISWAP:
                return fmt::format_to(ctx.out(), "ISWAP");
            case mindquantum::GateID::T:
                return fmt::format_to(ctx.out(), "T");
            case mindquantum::GateID::S:
                return fmt::format_to(ctx.out(), "S");
            case mindquantum::GateID::Tdag:
                return fmt::format_to(ctx.out(), "Tdag");
            case mindquantum::GateID::Sdag:
                return fmt::format_to(ctx.out(), "Sdag");
            case mindquantum::GateID::CNOT:
                return fmt::format_to(ctx.out(), "CNOT");
            case mindquantum::GateID::CZ:
                return fmt::format_to(ctx.out(), "CZ");
            default:
                return format_three(value, ctx);
        }
    }
};
#endif
