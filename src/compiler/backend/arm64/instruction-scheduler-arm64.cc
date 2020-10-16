// Copyright 2014 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/compiler/backend/instruction-scheduler.h"

namespace v8 {
namespace internal {
namespace compiler {

bool InstructionScheduler::SchedulerSupported() { return true; }

int InstructionScheduler::GetTargetInstructionFlags(
    const Instruction* instr) const {
  switch (instr->arch_opcode()) {
    case kArm64Add:
    case kArm64Add32:
    case kArm64And:
    case kArm64And32:
    case kArm64Bic:
    case kArm64Bic32:
    case kArm64Clz:
    case kArm64Clz32:
    case kArm64Cmp:
    case kArm64Cmp32:
    case kArm64Cmn:
    case kArm64Cmn32:
    case kArm64Cnt:
    case kArm64Tst:
    case kArm64Tst32:
    case kArm64Or:
    case kArm64Or32:
    case kArm64Orn:
    case kArm64Orn32:
    case kArm64Eor:
    case kArm64Eor32:
    case kArm64Eon:
    case kArm64Eon32:
    case kArm64Sub:
    case kArm64Sub32:
    case kArm64Mul:
    case kArm64Mul32:
    case kArm64Smull:
    case kArm64Smull2:
    case kArm64Umull:
    case kArm64Umull2:
    case kArm64Madd:
    case kArm64Madd32:
    case kArm64Msub:
    case kArm64Msub32:
    case kArm64Mneg:
    case kArm64Mneg32:
    case kArm64Idiv:
    case kArm64Idiv32:
    case kArm64Udiv:
    case kArm64Udiv32:
    case kArm64Imod:
    case kArm64Imod32:
    case kArm64Umod:
    case kArm64Umod32:
    case kArm64Not:
    case kArm64Not32:
    case kArm64Lsl:
    case kArm64Lsl32:
    case kArm64Lsr:
    case kArm64Lsr32:
    case kArm64Asr:
    case kArm64Asr32:
    case kArm64Ror:
    case kArm64Ror32:
    case kArm64Mov32:
    case kArm64Sxtb:
    case kArm64Sxtb32:
    case kArm64Sxth:
    case kArm64Sxth32:
    case kArm64Sxtw:
    case kArm64Sbfx:
    case kArm64Sbfx32:
    case kArm64Ubfx:
    case kArm64Ubfx32:
    case kArm64Ubfiz32:
    case kArm64Bfi:
    case kArm64Rbit:
    case kArm64Rbit32:
    case kArm64Rev:
    case kArm64Rev32:
    case kArm64Float32Cmp:
    case kArm64Float32Add:
    case kArm64Float32Sub:
    case kArm64Float32Mul:
    case kArm64Float32Div:
    case kArm64Float32Abs:
    case kArm64Float32Neg:
    case kArm64Float32Sqrt:
    case kArm64Float32Fnmul:
    case kArm64Float32RoundDown:
    case kArm64Float32Max:
    case kArm64Float32Min:
    case kArm64Float64Cmp:
    case kArm64Float64Add:
    case kArm64Float64Sub:
    case kArm64Float64Mul:
    case kArm64Float64Div:
    case kArm64Float64Max:
    case kArm64Float64Min:
    case kArm64Float64Abs:
    case kArm64Float64Neg:
    case kArm64Float64Sqrt:
    case kArm64Float64Fnmul:
    case kArm64Float64RoundDown:
    case kArm64Float64RoundTiesAway:
    case kArm64Float64RoundTruncate:
    case kArm64Float64RoundTiesEven:
    case kArm64Float64RoundUp:
    case kArm64Float32RoundTiesEven:
    case kArm64Float32RoundTruncate:
    case kArm64Float32RoundUp:
    case kArm64Float32ToFloat64:
    case kArm64Float64ToFloat32:
    case kArm64Float32ToInt32:
    case kArm64Float64ToInt32:
    case kArm64Float32ToUint32:
    case kArm64Float64ToUint32:
    case kArm64Float32ToInt64:
    case kArm64Float64ToInt64:
    case kArm64Float32ToUint64:
    case kArm64Float64ToUint64:
    case kArm64Int32ToFloat32:
    case kArm64Int32ToFloat64:
    case kArm64Int64ToFloat32:
    case kArm64Int64ToFloat64:
    case kArm64Uint32ToFloat32:
    case kArm64Uint32ToFloat64:
    case kArm64Uint64ToFloat32:
    case kArm64Uint64ToFloat64:
    case kArm64Float64ExtractLowWord32:
    case kArm64Float64ExtractHighWord32:
    case kArm64Float64InsertLowWord32:
    case kArm64Float64InsertHighWord32:
    case kArm64Float64Mod:
    case kArm64Float64MoveU64:
    case kArm64U64MoveFloat64:
    case kArm64Float64SilenceNaN:
    case kArm64F64x2Splat:
    case kArm64F64x2ExtractLane:
    case kArm64F64x2ReplaceLane:
    case kArm64F64x2Abs:
    case kArm64F64x2Neg:
    case kArm64F64x2Sqrt:
    case kArm64F64x2Add:
    case kArm64F64x2Sub:
    case kArm64F64x2Mul:
    case kArm64F64x2Div:
    case kArm64F64x2Min:
    case kArm64F64x2Max:
    case kArm64F64x2Eq:
    case kArm64F64x2Ne:
    case kArm64F64x2Lt:
    case kArm64F64x2Le:
    case kArm64F64x2Qfma:
    case kArm64F64x2Qfms:
    case kArm64F64x2Pmin:
    case kArm64F64x2Pmax:
    case kArm64F32x4Splat:
    case kArm64F32x4ExtractLane:
    case kArm64F32x4ReplaceLane:
    case kArm64F32x4SConvertI32x4:
    case kArm64F32x4UConvertI32x4:
    case kArm64F32x4Abs:
    case kArm64F32x4Neg:
    case kArm64F32x4Sqrt:
    case kArm64F32x4RecipApprox:
    case kArm64F32x4RecipSqrtApprox:
    case kArm64F32x4Add:
    case kArm64F32x4AddHoriz:
    case kArm64F32x4Sub:
    case kArm64F32x4Mul:
    case kArm64F32x4Div:
    case kArm64F32x4Min:
    case kArm64F32x4Max:
    case kArm64F32x4Eq:
    case kArm64F32x4Ne:
    case kArm64F32x4Lt:
    case kArm64F32x4Le:
    case kArm64F32x4Qfma:
    case kArm64F32x4Qfms:
    case kArm64F32x4Pmin:
    case kArm64F32x4Pmax:
    case kArm64I64x2Splat:
    case kArm64I64x2ExtractLane:
    case kArm64I64x2ReplaceLane:
    case kArm64I64x2Neg:
    case kArm64I64x2Shl:
    case kArm64I64x2ShrS:
    case kArm64I64x2Add:
    case kArm64I64x2Sub:
    case kArm64I64x2Mul:
    case kArm64I64x2Eq:
    case kArm64I64x2ShrU:
    case kArm64I32x4Splat:
    case kArm64I32x4ExtractLane:
    case kArm64I32x4ReplaceLane:
    case kArm64I32x4SConvertF32x4:
    case kArm64Sxtl:
    case kArm64Sxtl2:
    case kArm64Uxtl:
    case kArm64Uxtl2:
    case kArm64I32x4Neg:
    case kArm64I32x4Shl:
    case kArm64I32x4ShrS:
    case kArm64I32x4Add:
    case kArm64I32x4AddHoriz:
    case kArm64I32x4Sub:
    case kArm64I32x4Mul:
    case kArm64I32x4Mla:
    case kArm64I32x4Mls:
    case kArm64I32x4MinS:
    case kArm64I32x4MaxS:
    case kArm64I32x4Eq:
    case kArm64I32x4Ne:
    case kArm64I32x4GtS:
    case kArm64I32x4GeS:
    case kArm64I32x4UConvertF32x4:
    case kArm64I32x4ShrU:
    case kArm64I32x4MinU:
    case kArm64I32x4MaxU:
    case kArm64I32x4GtU:
    case kArm64I32x4GeU:
    case kArm64I32x4Abs:
    case kArm64I32x4BitMask:
    case kArm64I32x4DotI16x8S:
    case kArm64I16x8Splat:
    case kArm64I16x8ExtractLaneU:
    case kArm64I16x8ExtractLaneS:
    case kArm64I16x8ReplaceLane:
    case kArm64I16x8Neg:
    case kArm64I16x8Shl:
    case kArm64I16x8ShrS:
    case kArm64I16x8SConvertI32x4:
    case kArm64I16x8Add:
    case kArm64I16x8AddSatS:
    case kArm64I16x8AddHoriz:
    case kArm64I16x8Sub:
    case kArm64I16x8SubSatS:
    case kArm64I16x8Mul:
    case kArm64I16x8Mla:
    case kArm64I16x8Mls:
    case kArm64I16x8MinS:
    case kArm64I16x8MaxS:
    case kArm64I16x8Eq:
    case kArm64I16x8Ne:
    case kArm64I16x8GtS:
    case kArm64I16x8GeS:
    case kArm64I16x8ShrU:
    case kArm64I16x8UConvertI32x4:
    case kArm64I16x8AddSatU:
    case kArm64I16x8SubSatU:
    case kArm64I16x8MinU:
    case kArm64I16x8MaxU:
    case kArm64I16x8GtU:
    case kArm64I16x8GeU:
    case kArm64I16x8RoundingAverageU:
    case kArm64I16x8Q15MulRSatS:
    case kArm64I16x8Abs:
    case kArm64I16x8BitMask:
    case kArm64I8x16Splat:
    case kArm64I8x16ExtractLaneU:
    case kArm64I8x16ExtractLaneS:
    case kArm64I8x16ReplaceLane:
    case kArm64I8x16Neg:
    case kArm64I8x16Shl:
    case kArm64I8x16ShrS:
    case kArm64I8x16SConvertI16x8:
    case kArm64I8x16Add:
    case kArm64I8x16AddSatS:
    case kArm64I8x16Sub:
    case kArm64I8x16SubSatS:
    case kArm64I8x16Mul:
    case kArm64I8x16Mla:
    case kArm64I8x16Mls:
    case kArm64I8x16MinS:
    case kArm64I8x16MaxS:
    case kArm64I8x16Eq:
    case kArm64I8x16Ne:
    case kArm64I8x16GtS:
    case kArm64I8x16GeS:
    case kArm64I8x16UConvertI16x8:
    case kArm64I8x16AddSatU:
    case kArm64I8x16SubSatU:
    case kArm64I8x16ShrU:
    case kArm64I8x16MinU:
    case kArm64I8x16MaxU:
    case kArm64I8x16GtU:
    case kArm64I8x16GeU:
    case kArm64I8x16RoundingAverageU:
    case kArm64I8x16Abs:
    case kArm64I8x16BitMask:
    case kArm64S128Const:
    case kArm64S128Zero:
    case kArm64S128Dup:
    case kArm64S128And:
    case kArm64S128Or:
    case kArm64S128Xor:
    case kArm64S128Not:
    case kArm64S128Select:
    case kArm64S128AndNot:
    case kArm64S32x4ZipLeft:
    case kArm64S32x4ZipRight:
    case kArm64S32x4UnzipLeft:
    case kArm64S32x4UnzipRight:
    case kArm64S32x4TransposeLeft:
    case kArm64S32x4TransposeRight:
    case kArm64S32x4Shuffle:
    case kArm64S16x8ZipLeft:
    case kArm64S16x8ZipRight:
    case kArm64S16x8UnzipLeft:
    case kArm64S16x8UnzipRight:
    case kArm64S16x8TransposeLeft:
    case kArm64S16x8TransposeRight:
    case kArm64S8x16ZipLeft:
    case kArm64S8x16ZipRight:
    case kArm64S8x16UnzipLeft:
    case kArm64S8x16UnzipRight:
    case kArm64S8x16TransposeLeft:
    case kArm64S8x16TransposeRight:
    case kArm64S8x16Concat:
    case kArm64I8x16Swizzle:
    case kArm64I8x16Shuffle:
    case kArm64S32x2Reverse:
    case kArm64S16x4Reverse:
    case kArm64S16x2Reverse:
    case kArm64S8x8Reverse:
    case kArm64S8x4Reverse:
    case kArm64S8x2Reverse:
    case kArm64V128AnyTrue:
    case kArm64V32x4AllTrue:
    case kArm64V16x8AllTrue:
    case kArm64V8x16AllTrue:
    case kArm64TestAndBranch32:
    case kArm64TestAndBranch:
    case kArm64CompareAndBranch32:
    case kArm64CompareAndBranch:
      return kNoOpcodeFlags;

    case kArm64LdrS:
    case kArm64LdrD:
    case kArm64LdrQ:
    case kArm64Ldrb:
    case kArm64Ldrsb:
    case kArm64Ldrh:
    case kArm64Ldrsh:
    case kArm64Ldrsw:
    case kArm64LdrW:
    case kArm64Ldr:
    case kArm64LdrDecompressTaggedSigned:
    case kArm64LdrDecompressTaggedPointer:
    case kArm64LdrDecompressAnyTagged:
    case kArm64Peek:
    case kArm64LoadSplat:
    case kArm64S128Load8x8S:
    case kArm64S128Load8x8U:
    case kArm64S128Load16x4S:
    case kArm64S128Load16x4U:
    case kArm64S128Load32x2S:
    case kArm64S128Load32x2U:
    case kArm64S128LoadMem32Zero:
    case kArm64S128LoadMem64Zero:
      return kIsLoadOperation;

    case kArm64Claim:
    case kArm64Poke:
    case kArm64PokePair:
    case kArm64StrS:
    case kArm64StrD:
    case kArm64StrQ:
    case kArm64Strb:
    case kArm64Strh:
    case kArm64StrW:
    case kArm64Str:
    case kArm64StrCompressTagged:
    case kArm64DmbIsh:
    case kArm64DsbIsb:
      return kHasSideEffect;

    case kArm64Word64AtomicLoadUint8:
    case kArm64Word64AtomicLoadUint16:
    case kArm64Word64AtomicLoadUint32:
    case kArm64Word64AtomicLoadUint64:
      return kIsLoadOperation;

    case kArm64Word64AtomicStoreWord8:
    case kArm64Word64AtomicStoreWord16:
    case kArm64Word64AtomicStoreWord32:
    case kArm64Word64AtomicStoreWord64:
    case kArm64Word64AtomicAddUint8:
    case kArm64Word64AtomicAddUint16:
    case kArm64Word64AtomicAddUint32:
    case kArm64Word64AtomicAddUint64:
    case kArm64Word64AtomicSubUint8:
    case kArm64Word64AtomicSubUint16:
    case kArm64Word64AtomicSubUint32:
    case kArm64Word64AtomicSubUint64:
    case kArm64Word64AtomicAndUint8:
    case kArm64Word64AtomicAndUint16:
    case kArm64Word64AtomicAndUint32:
    case kArm64Word64AtomicAndUint64:
    case kArm64Word64AtomicOrUint8:
    case kArm64Word64AtomicOrUint16:
    case kArm64Word64AtomicOrUint32:
    case kArm64Word64AtomicOrUint64:
    case kArm64Word64AtomicXorUint8:
    case kArm64Word64AtomicXorUint16:
    case kArm64Word64AtomicXorUint32:
    case kArm64Word64AtomicXorUint64:
    case kArm64Word64AtomicExchangeUint8:
    case kArm64Word64AtomicExchangeUint16:
    case kArm64Word64AtomicExchangeUint32:
    case kArm64Word64AtomicExchangeUint64:
    case kArm64Word64AtomicCompareExchangeUint8:
    case kArm64Word64AtomicCompareExchangeUint16:
    case kArm64Word64AtomicCompareExchangeUint32:
    case kArm64Word64AtomicCompareExchangeUint64:
      return kHasSideEffect;

#define CASE(Name) case k##Name:
      COMMON_ARCH_OPCODE_LIST(CASE)
#undef CASE
      // Already covered in architecture independent code.
      UNREACHABLE();
  }

  UNREACHABLE();
}

int InstructionScheduler::GetInstructionLatency(const Instruction* instr) {
  // Basic latency modeling for arm64 instructions. They have been determined
  // in an empirical way.
  switch (instr->arch_opcode()) {
    case kArm64Add:
    case kArm64Add32:
    case kArm64And:
    case kArm64And32:
    case kArm64Bic:
    case kArm64Bic32:
    case kArm64Cmn:
    case kArm64Cmn32:
    case kArm64Cmp:
    case kArm64Cmp32:
    case kArm64Eon:
    case kArm64Eon32:
    case kArm64Eor:
    case kArm64Eor32:
    case kArm64Not:
    case kArm64Not32:
    case kArm64Or:
    case kArm64Or32:
    case kArm64Orn:
    case kArm64Orn32:
    case kArm64Sub:
    case kArm64Sub32:
    case kArm64Tst:
    case kArm64Tst32:
      if (instr->addressing_mode() != kMode_None) {
        return 3;
      } else {
        return 1;
      }

    case kArm64Clz:
    case kArm64Clz32:
    case kArm64Sbfx:
    case kArm64Sbfx32:
    case kArm64Sxtb32:
    case kArm64Sxth32:
    case kArm64Sxtw:
    case kArm64Ubfiz32:
    case kArm64Ubfx:
    case kArm64Ubfx32:
      return 1;

    case kArm64Lsl:
    case kArm64Lsl32:
    case kArm64Lsr:
    case kArm64Lsr32:
    case kArm64Asr:
    case kArm64Asr32:
    case kArm64Ror:
    case kArm64Ror32:
      return 1;

    case kArm64LdrDecompressTaggedSigned:
    case kArm64LdrDecompressTaggedPointer:
    case kArm64LdrDecompressAnyTagged:
    case kArm64Ldr:
    case kArm64LdrD:
    case kArm64LdrS:
    case kArm64LdrW:
    case kArm64Ldrb:
    case kArm64Ldrh:
    case kArm64Ldrsb:
    case kArm64Ldrsh:
    case kArm64Ldrsw:
      return 11;

    case kArm64Str:
    case kArm64StrD:
    case kArm64StrS:
    case kArm64StrW:
    case kArm64Strb:
    case kArm64Strh:
      return 1;

    case kArm64Madd32:
    case kArm64Mneg32:
    case kArm64Msub32:
    case kArm64Mul32:
      return 3;

    case kArm64Madd:
    case kArm64Mneg:
    case kArm64Msub:
    case kArm64Mul:
      return 5;

    case kArm64Idiv32:
    case kArm64Udiv32:
      return 12;

    case kArm64Idiv:
    case kArm64Udiv:
      return 20;

    case kArm64Float32Add:
    case kArm64Float32Sub:
    case kArm64Float64Add:
    case kArm64Float64Sub:
      return 5;

    case kArm64Float32Abs:
    case kArm64Float32Cmp:
    case kArm64Float32Neg:
    case kArm64Float64Abs:
    case kArm64Float64Cmp:
    case kArm64Float64Neg:
      return 3;

    case kArm64Float32Div:
    case kArm64Float32Sqrt:
      return 12;

    case kArm64Float64Div:
    case kArm64Float64Sqrt:
      return 19;

    case kArm64Float32RoundDown:
    case kArm64Float32RoundTiesEven:
    case kArm64Float32RoundTruncate:
    case kArm64Float32RoundUp:
    case kArm64Float64RoundDown:
    case kArm64Float64RoundTiesAway:
    case kArm64Float64RoundTiesEven:
    case kArm64Float64RoundTruncate:
    case kArm64Float64RoundUp:
      return 5;

    case kArm64Float32ToFloat64:
    case kArm64Float64ToFloat32:
    case kArm64Float64ToInt32:
    case kArm64Float64ToUint32:
    case kArm64Float32ToInt64:
    case kArm64Float64ToInt64:
    case kArm64Float32ToUint64:
    case kArm64Float64ToUint64:
    case kArm64Int32ToFloat64:
    case kArm64Int64ToFloat32:
    case kArm64Int64ToFloat64:
    case kArm64Uint32ToFloat64:
    case kArm64Uint64ToFloat32:
    case kArm64Uint64ToFloat64:
      return 5;

    default:
      return 2;
  }
}

}  // namespace compiler
}  // namespace internal
}  // namespace v8
