/*
Copyright (c) 2018 tevador

This file is part of RandomX.

RandomX is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

RandomX is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RandomX.  If not, see<http://www.gnu.org/licenses/>.
*/

#pragma once

#include <cstdint>
#include <iostream>

namespace RandomX {

	class Instruction;

	typedef void(Instruction::*InstructionVisualizer)(std::ostream&) const;

	namespace InstructionType {
		constexpr int IADD_R = 0;
		constexpr int IADD_M = 1;
		constexpr int IADD_RC = 2;
		constexpr int ISUB_R = 3;
		constexpr int ISUB_M = 4;
		constexpr int IMUL_9C = 5;
		constexpr int IMUL_R = 6;
		constexpr int IMUL_M = 7;
		constexpr int IMULH_R = 8;
		constexpr int IMULH_M = 9;
		constexpr int ISMULH_R = 10;
		constexpr int ISMULH_M = 11;
		constexpr int IDIV_C = 12;
		constexpr int ISDIV_C = 13;
		constexpr int INEG_R = 14;
		constexpr int IXOR_R = 15;
		constexpr int IXOR_M = 16;
		constexpr int IROR_R = 17;
		constexpr int IROL_R = 18;
		constexpr int ISWAP_R = 19;
		constexpr int FPSWAP_R = 20;
		constexpr int FPADD_R = 21;
		constexpr int FPADD_M = 22;
		constexpr int FPSUB_R = 23;
		constexpr int FPSUB_M = 24;
		constexpr int FPNEG_R = 25;
		constexpr int FPMUL_R = 26;
		constexpr int FPMUL_M = 27;
		constexpr int FPDIV_R = 28;
		constexpr int FPDIV_M = 29;
		constexpr int FPSQRT_R = 30;
		constexpr int COND_R = 31;
		constexpr int COND_M = 32;
		constexpr int CFROUND = 33;
		constexpr int ISTORE = 34;
		constexpr int FSTORE = 35;
		constexpr int NOP = 36;
	}

	class Instruction {
	public:
		uint8_t opcode;
		uint8_t dst;
		uint8_t src;
		uint8_t mod;
		int32_t imm32;
		const char* getName() const {
			return names[opcode];
		}
		friend std::ostream& operator<<(std::ostream& os, const Instruction& i) {
			i.print(os);
			return os;
		}
	private:
		void print(std::ostream&) const;
		static const char* names[256];
		static InstructionVisualizer engine[256];

		void genAddressReg(std::ostream& os) const;
		void genAddressImm(std::ostream& os) const;
		void genAddressRegDst(std::ostream&) const;

		void  h_IADD_R(std::ostream&) const;
		void  h_IADD_M(std::ostream&) const;
		void  h_IADD_RC(std::ostream&) const;
		void  h_ISUB_R(std::ostream&) const;
		void  h_ISUB_M(std::ostream&) const;
		void  h_IMUL_9C(std::ostream&) const;
		void  h_IMUL_R(std::ostream&) const;
		void  h_IMUL_M(std::ostream&) const;
		void  h_IMULH_R(std::ostream&) const;
		void  h_IMULH_M(std::ostream&) const;
		void  h_ISMULH_R(std::ostream&) const;
		void  h_ISMULH_M(std::ostream&) const;
		void  h_IDIV_C(std::ostream&) const;
		void  h_ISDIV_C(std::ostream&) const;
		void  h_INEG_R(std::ostream&) const;
		void  h_IXOR_R(std::ostream&) const;
		void  h_IXOR_M(std::ostream&) const;
		void  h_IROR_R(std::ostream&) const;
		void  h_IROL_R(std::ostream&) const;
		void  h_ISWAP_R(std::ostream&) const;
		void  h_FPSWAP_R(std::ostream&) const;
		void  h_FPADD_R(std::ostream&) const;
		void  h_FPADD_M(std::ostream&) const;
		void  h_FPSUB_R(std::ostream&) const;
		void  h_FPSUB_M(std::ostream&) const;
		void  h_FPNEG_R(std::ostream&) const;
		void  h_FPMUL_R(std::ostream&) const;
		void  h_FPMUL_M(std::ostream&) const;
		void  h_FPDIV_R(std::ostream&) const;
		void  h_FPDIV_M(std::ostream&) const;
		void  h_FPSQRT_R(std::ostream&) const;
		void  h_COND_R(std::ostream&) const;
		void  h_COND_M(std::ostream&) const;
		void  h_CFROUND(std::ostream&) const;
		void  h_ISTORE(std::ostream&) const;
		void  h_FSTORE(std::ostream&) const;
		void  h_NOP(std::ostream&) const;
	};

	static_assert(sizeof(Instruction) == 8, "Invalid alignment of struct Instruction");

}