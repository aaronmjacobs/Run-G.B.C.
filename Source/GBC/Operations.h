#ifndef GBC_OPERATIONS_H
#define GBC_OPERATIONS_H

#include "GBC/CPU.h"

#include <array>

namespace GBC {

namespace {

const std::array<Operation, 256> kOperations = {
   /* 0x00 */ Operation(Ins::kNOP, Opr::kNone, Opr::kNone, 4),
   /* 0x01 */ Operation(Ins::kLD, Opr::kBC, Opr::kImm16, 12),
   /* 0x02 */ Operation(Ins::kLD, Opr::kDrefBC, Opr::kA, 8),
   /* 0x03 */ Operation(Ins::kINC, Opr::kBC, Opr::kNone, 8),
   /* 0x04 */ Operation(Ins::kINC, Opr::kB, Opr::kNone, 4),
   /* 0x05 */ Operation(Ins::kDEC, Opr::kB, Opr::kNone, 4),
   /* 0x06 */ Operation(Ins::kLD, Opr::kB, Opr::kImm8, 8),
   /* 0x07 */ Operation(Ins::kRLCA, Opr::kNone, Opr::kNone, 4),
   /* 0x08 */ Operation(Ins::kLD, Opr::kDrefImm16, Opr::kSP, 20),
   /* 0x09 */ Operation(Ins::kADD, Opr::kHL, Opr::kBC, 8),
   /* 0x0A */ Operation(Ins::kLD, Opr::kA, Opr::kDrefBC, 8),
   /* 0x0B */ Operation(Ins::kDEC, Opr::kBC, Opr::kNone, 8),
   /* 0x0C */ Operation(Ins::kINC, Opr::kC, Opr::kNone, 4),
   /* 0x0D */ Operation(Ins::kDEC, Opr::kC, Opr::kNone, 4),
   /* 0x0E */ Operation(Ins::kLD, Opr::kC, Opr::kImm8, 8),
   /* 0x0F */ Operation(Ins::kRRCA, Opr::kNone, Opr::kNone, 4),
   /* 0x10 */ Operation(Ins::kSTOP, Opr::kNone, Opr::kNone, 4),
   /* 0x11 */ Operation(Ins::kLD, Opr::kDE, Opr::kImm16, 12),
   /* 0x12 */ Operation(Ins::kLD, Opr::kDrefDE, Opr::kA, 8),
   /* 0x13 */ Operation(Ins::kINC, Opr::kDE, Opr::kNone, 8),
   /* 0x14 */ Operation(Ins::kINC, Opr::kD, Opr::kNone, 4),
   /* 0x15 */ Operation(Ins::kDEC, Opr::kD, Opr::kNone, 4),
   /* 0x16 */ Operation(Ins::kLD, Opr::kD, Opr::kImm8, 8),
   /* 0x17 */ Operation(Ins::kRLA, Opr::kNone, Opr::kNone, 4),
   /* 0x18 */ Operation(Ins::kJR, Opr::kImm8Signed, Opr::kNone, 12),
   /* 0x19 */ Operation(Ins::kADD, Opr::kHL, Opr::kDE, 8),
   /* 0x1A */ Operation(Ins::kLD, Opr::kA, Opr::kDrefDE, 8),
   /* 0x1B */ Operation(Ins::kDEC, Opr::kDE, Opr::kNone, 8),
   /* 0x1C */ Operation(Ins::kINC, Opr::kE, Opr::kNone, 4),
   /* 0x1D */ Operation(Ins::kDEC, Opr::kE, Opr::kNone, 4),
   /* 0x1E */ Operation(Ins::kLD, Opr::kE, Opr::kImm8, 8),
   /* 0x1F */ Operation(Ins::kRRA, Opr::kNone, Opr::kNone, 4),
   /* 0x20 */ Operation(Ins::kJR, Opr::kFlagNZ, Opr::kImm8Signed, 12),
   /* 0x21 */ Operation(Ins::kLD, Opr::kHL, Opr::kImm16, 12),
   /* 0x22 */ Operation(Ins::kLDI, Opr::kDrefHL, Opr::kA, 8),
   /* 0x23 */ Operation(Ins::kINC, Opr::kHL, Opr::kNone, 8),
   /* 0x24 */ Operation(Ins::kINC, Opr::kH, Opr::kNone, 4),
   /* 0x25 */ Operation(Ins::kDEC, Opr::kH, Opr::kNone, 4),
   /* 0x26 */ Operation(Ins::kLD, Opr::kH, Opr::kImm8, 8),
   /* 0x27 */ Operation(Ins::kDAA, Opr::kNone, Opr::kNone, 4),
   /* 0x28 */ Operation(Ins::kJR, Opr::kFlagZ, Opr::kImm8Signed, 12),
   /* 0x29 */ Operation(Ins::kADD, Opr::kHL, Opr::kHL, 8),
   /* 0x2A */ Operation(Ins::kLDI, Opr::kA, Opr::kDrefHL, 8),
   /* 0x2B */ Operation(Ins::kDEC, Opr::kHL, Opr::kNone, 8),
   /* 0x2C */ Operation(Ins::kINC, Opr::kL, Opr::kNone, 4),
   /* 0x2D */ Operation(Ins::kDEC, Opr::kL, Opr::kNone, 4),
   /* 0x2E */ Operation(Ins::kLD, Opr::kL, Opr::kImm8, 8),
   /* 0x2F */ Operation(Ins::kCPL, Opr::kNone, Opr::kNone, 4),
   /* 0x30 */ Operation(Ins::kJR, Opr::kFlagNC, Opr::kImm8Signed, 12),
   /* 0x31 */ Operation(Ins::kLD, Opr::kSP, Opr::kImm16, 12),
   /* 0x32 */ Operation(Ins::kLDD, Opr::kDrefHL, Opr::kA, 8),
   /* 0x33 */ Operation(Ins::kINC, Opr::kSP, Opr::kNone, 8),
   /* 0x34 */ Operation(Ins::kINC, Opr::kDrefHL, Opr::kNone, 12),
   /* 0x35 */ Operation(Ins::kDEC, Opr::kDrefHL, Opr::kNone, 12),
   /* 0x36 */ Operation(Ins::kLD, Opr::kDrefHL, Opr::kImm8, 12),
   /* 0x37 */ Operation(Ins::kSCF, Opr::kNone, Opr::kNone, 4),
   /* 0x38 */ Operation(Ins::kJR, Opr::kFlagC, Opr::kImm8Signed, 12),
   /* 0x39 */ Operation(Ins::kADD, Opr::kHL, Opr::kSP, 8),
   /* 0x3A */ Operation(Ins::kLDD, Opr::kA, Opr::kDrefHL, 8),
   /* 0x3B */ Operation(Ins::kDEC, Opr::kSP, Opr::kNone, 8),
   /* 0x3C */ Operation(Ins::kINC, Opr::kA, Opr::kNone, 4),
   /* 0x3D */ Operation(Ins::kDEC, Opr::kA, Opr::kNone, 4),
   /* 0x3E */ Operation(Ins::kLD, Opr::kA, Opr::kImm8, 8),
   /* 0x3F */ Operation(Ins::kCCF, Opr::kNone, Opr::kNone, 4),
   /* 0x40 */ Operation(Ins::kLD, Opr::kB, Opr::kB, 4),
   /* 0x41 */ Operation(Ins::kLD, Opr::kB, Opr::kC, 4),
   /* 0x42 */ Operation(Ins::kLD, Opr::kB, Opr::kD, 4),
   /* 0x43 */ Operation(Ins::kLD, Opr::kB, Opr::kE, 4),
   /* 0x44 */ Operation(Ins::kLD, Opr::kB, Opr::kH, 4),
   /* 0x45 */ Operation(Ins::kLD, Opr::kB, Opr::kL, 4),
   /* 0x46 */ Operation(Ins::kLD, Opr::kB, Opr::kDrefHL, 8),
   /* 0x47 */ Operation(Ins::kLD, Opr::kB, Opr::kA, 4),
   /* 0x48 */ Operation(Ins::kLD, Opr::kC, Opr::kB, 4),
   /* 0x49 */ Operation(Ins::kLD, Opr::kC, Opr::kC, 4),
   /* 0x4A */ Operation(Ins::kLD, Opr::kC, Opr::kD, 4),
   /* 0x4B */ Operation(Ins::kLD, Opr::kC, Opr::kE, 4),
   /* 0x4C */ Operation(Ins::kLD, Opr::kC, Opr::kH, 4),
   /* 0x4D */ Operation(Ins::kLD, Opr::kC, Opr::kL, 4),
   /* 0x4E */ Operation(Ins::kLD, Opr::kC, Opr::kDrefHL, 8),
   /* 0x4F */ Operation(Ins::kLD, Opr::kC, Opr::kA, 4),
   /* 0x50 */ Operation(Ins::kLD, Opr::kD, Opr::kB, 4),
   /* 0x51 */ Operation(Ins::kLD, Opr::kD, Opr::kC, 4),
   /* 0x52 */ Operation(Ins::kLD, Opr::kD, Opr::kD, 4),
   /* 0x53 */ Operation(Ins::kLD, Opr::kD, Opr::kE, 4),
   /* 0x54 */ Operation(Ins::kLD, Opr::kD, Opr::kH, 4),
   /* 0x55 */ Operation(Ins::kLD, Opr::kD, Opr::kL, 4),
   /* 0x56 */ Operation(Ins::kLD, Opr::kD, Opr::kDrefHL, 8),
   /* 0x57 */ Operation(Ins::kLD, Opr::kD, Opr::kA, 4),
   /* 0x58 */ Operation(Ins::kLD, Opr::kE, Opr::kB, 4),
   /* 0x59 */ Operation(Ins::kLD, Opr::kE, Opr::kC, 4),
   /* 0x5A */ Operation(Ins::kLD, Opr::kE, Opr::kD, 4),
   /* 0x5B */ Operation(Ins::kLD, Opr::kE, Opr::kE, 4),
   /* 0x5C */ Operation(Ins::kLD, Opr::kE, Opr::kH, 4),
   /* 0x5D */ Operation(Ins::kLD, Opr::kE, Opr::kL, 4),
   /* 0x5E */ Operation(Ins::kLD, Opr::kE, Opr::kDrefHL, 8),
   /* 0x5F */ Operation(Ins::kLD, Opr::kE, Opr::kA, 4),
   /* 0x60 */ Operation(Ins::kLD, Opr::kH, Opr::kB, 4),
   /* 0x61 */ Operation(Ins::kLD, Opr::kH, Opr::kC, 4),
   /* 0x62 */ Operation(Ins::kLD, Opr::kH, Opr::kD, 4),
   /* 0x63 */ Operation(Ins::kLD, Opr::kH, Opr::kE, 4),
   /* 0x64 */ Operation(Ins::kLD, Opr::kH, Opr::kH, 4),
   /* 0x65 */ Operation(Ins::kLD, Opr::kH, Opr::kL, 4),
   /* 0x66 */ Operation(Ins::kLD, Opr::kH, Opr::kDrefHL, 8),
   /* 0x67 */ Operation(Ins::kLD, Opr::kH, Opr::kA, 4),
   /* 0x68 */ Operation(Ins::kLD, Opr::kL, Opr::kB, 4),
   /* 0x69 */ Operation(Ins::kLD, Opr::kL, Opr::kC, 4),
   /* 0x6A */ Operation(Ins::kLD, Opr::kL, Opr::kD, 4),
   /* 0x6B */ Operation(Ins::kLD, Opr::kL, Opr::kE, 4),
   /* 0x6C */ Operation(Ins::kLD, Opr::kL, Opr::kH, 4),
   /* 0x6D */ Operation(Ins::kLD, Opr::kL, Opr::kL, 4),
   /* 0x6E */ Operation(Ins::kLD, Opr::kL, Opr::kDrefHL, 8),
   /* 0x6F */ Operation(Ins::kLD, Opr::kL, Opr::kA, 4),
   /* 0x70 */ Operation(Ins::kLD, Opr::kDrefHL, Opr::kB, 8),
   /* 0x71 */ Operation(Ins::kLD, Opr::kDrefHL, Opr::kC, 8),
   /* 0x72 */ Operation(Ins::kLD, Opr::kDrefHL, Opr::kD, 8),
   /* 0x73 */ Operation(Ins::kLD, Opr::kDrefHL, Opr::kE, 8),
   /* 0x74 */ Operation(Ins::kLD, Opr::kDrefHL, Opr::kH, 8),
   /* 0x75 */ Operation(Ins::kLD, Opr::kDrefHL, Opr::kL, 8),
   /* 0x76 */ Operation(Ins::kHALT, Opr::kNone, Opr::kNone, 4),
   /* 0x77 */ Operation(Ins::kLD, Opr::kDrefHL, Opr::kA, 8),
   /* 0x78 */ Operation(Ins::kLD, Opr::kA, Opr::kB, 4),
   /* 0x79 */ Operation(Ins::kLD, Opr::kA, Opr::kC, 4),
   /* 0x7A */ Operation(Ins::kLD, Opr::kA, Opr::kD, 4),
   /* 0x7B */ Operation(Ins::kLD, Opr::kA, Opr::kE, 4),
   /* 0x7C */ Operation(Ins::kLD, Opr::kA, Opr::kH, 4),
   /* 0x7D */ Operation(Ins::kLD, Opr::kA, Opr::kL, 4),
   /* 0x7E */ Operation(Ins::kLD, Opr::kA, Opr::kDrefHL, 8),
   /* 0x7F */ Operation(Ins::kLD, Opr::kA, Opr::kA, 4),
   /* 0x80 */ Operation(Ins::kADD, Opr::kA, Opr::kB, 4),
   /* 0x81 */ Operation(Ins::kADD, Opr::kA, Opr::kC, 4),
   /* 0x82 */ Operation(Ins::kADD, Opr::kA, Opr::kD, 4),
   /* 0x83 */ Operation(Ins::kADD, Opr::kA, Opr::kE, 4),
   /* 0x84 */ Operation(Ins::kADD, Opr::kA, Opr::kH, 4),
   /* 0x85 */ Operation(Ins::kADD, Opr::kA, Opr::kL, 4),
   /* 0x86 */ Operation(Ins::kADD, Opr::kA, Opr::kDrefHL, 8),
   /* 0x87 */ Operation(Ins::kADD, Opr::kA, Opr::kA, 4),
   /* 0x88 */ Operation(Ins::kADC, Opr::kA, Opr::kB, 4),
   /* 0x89 */ Operation(Ins::kADC, Opr::kA, Opr::kC, 4),
   /* 0x8A */ Operation(Ins::kADC, Opr::kA, Opr::kD, 4),
   /* 0x8B */ Operation(Ins::kADC, Opr::kA, Opr::kE, 4),
   /* 0x8C */ Operation(Ins::kADC, Opr::kA, Opr::kH, 4),
   /* 0x8D */ Operation(Ins::kADC, Opr::kA, Opr::kL, 4),
   /* 0x8E */ Operation(Ins::kADC, Opr::kA, Opr::kDrefHL, 8),
   /* 0x8F */ Operation(Ins::kADC, Opr::kA, Opr::kA, 4),
   /* 0x90 */ Operation(Ins::kSUB, Opr::kB, Opr::kNone, 4),
   /* 0x91 */ Operation(Ins::kSUB, Opr::kC, Opr::kNone, 4),
   /* 0x92 */ Operation(Ins::kSUB, Opr::kD, Opr::kNone, 4),
   /* 0x93 */ Operation(Ins::kSUB, Opr::kE, Opr::kNone, 4),
   /* 0x94 */ Operation(Ins::kSUB, Opr::kH, Opr::kNone, 4),
   /* 0x95 */ Operation(Ins::kSUB, Opr::kL, Opr::kNone, 4),
   /* 0x96 */ Operation(Ins::kSUB, Opr::kDrefHL, Opr::kNone, 8),
   /* 0x97 */ Operation(Ins::kSUB, Opr::kA, Opr::kNone, 4),
   /* 0x98 */ Operation(Ins::kSBC, Opr::kA, Opr::kB, 4),
   /* 0x99 */ Operation(Ins::kSBC, Opr::kA, Opr::kC, 4),
   /* 0x9A */ Operation(Ins::kSBC, Opr::kA, Opr::kD, 4),
   /* 0x9B */ Operation(Ins::kSBC, Opr::kA, Opr::kE, 4),
   /* 0x9C */ Operation(Ins::kSBC, Opr::kA, Opr::kH, 4),
   /* 0x9D */ Operation(Ins::kSBC, Opr::kA, Opr::kL, 4),
   /* 0x9E */ Operation(Ins::kSBC, Opr::kA, Opr::kDrefHL, 8),
   /* 0x9F */ Operation(Ins::kSBC, Opr::kA, Opr::kA, 4),
   /* 0xA0 */ Operation(Ins::kAND, Opr::kB, Opr::kNone, 4),
   /* 0xA1 */ Operation(Ins::kAND, Opr::kC, Opr::kNone, 4),
   /* 0xA2 */ Operation(Ins::kAND, Opr::kD, Opr::kNone, 4),
   /* 0xA3 */ Operation(Ins::kAND, Opr::kE, Opr::kNone, 4),
   /* 0xA4 */ Operation(Ins::kAND, Opr::kH, Opr::kNone, 4),
   /* 0xA5 */ Operation(Ins::kAND, Opr::kL, Opr::kNone, 4),
   /* 0xA6 */ Operation(Ins::kAND, Opr::kDrefHL, Opr::kNone, 8),
   /* 0xA7 */ Operation(Ins::kAND, Opr::kA, Opr::kNone, 4),
   /* 0xA8 */ Operation(Ins::kXOR, Opr::kB, Opr::kNone, 4),
   /* 0xA9 */ Operation(Ins::kXOR, Opr::kC, Opr::kNone, 4),
   /* 0xAA */ Operation(Ins::kXOR, Opr::kD, Opr::kNone, 4),
   /* 0xAB */ Operation(Ins::kXOR, Opr::kE, Opr::kNone, 4),
   /* 0xAC */ Operation(Ins::kXOR, Opr::kH, Opr::kNone, 4),
   /* 0xAD */ Operation(Ins::kXOR, Opr::kL, Opr::kNone, 4),
   /* 0xAE */ Operation(Ins::kXOR, Opr::kDrefHL, Opr::kNone, 8),
   /* 0xAF */ Operation(Ins::kXOR, Opr::kA, Opr::kNone, 4),
   /* 0xB0 */ Operation(Ins::kOR, Opr::kB, Opr::kNone, 4),
   /* 0xB1 */ Operation(Ins::kOR, Opr::kC, Opr::kNone, 4),
   /* 0xB2 */ Operation(Ins::kOR, Opr::kD, Opr::kNone, 4),
   /* 0xB3 */ Operation(Ins::kOR, Opr::kE, Opr::kNone, 4),
   /* 0xB4 */ Operation(Ins::kOR, Opr::kH, Opr::kNone, 4),
   /* 0xB5 */ Operation(Ins::kOR, Opr::kL, Opr::kNone, 4),
   /* 0xB6 */ Operation(Ins::kOR, Opr::kDrefHL, Opr::kNone, 8),
   /* 0xB7 */ Operation(Ins::kOR, Opr::kA, Opr::kNone, 4),
   /* 0xB8 */ Operation(Ins::kCP, Opr::kB, Opr::kNone, 4),
   /* 0xB9 */ Operation(Ins::kCP, Opr::kC, Opr::kNone, 4),
   /* 0xBA */ Operation(Ins::kCP, Opr::kD, Opr::kNone, 4),
   /* 0xBB */ Operation(Ins::kCP, Opr::kE, Opr::kNone, 4),
   /* 0xBC */ Operation(Ins::kCP, Opr::kH, Opr::kNone, 4),
   /* 0xBD */ Operation(Ins::kCP, Opr::kL, Opr::kNone, 4),
   /* 0xBE */ Operation(Ins::kCP, Opr::kDrefHL, Opr::kNone, 8),
   /* 0xBF */ Operation(Ins::kCP, Opr::kA, Opr::kNone, 4),
   /* 0xC0 */ Operation(Ins::kRET, Opr::kFlagNZ, Opr::kNone, 20),
   /* 0xC1 */ Operation(Ins::kPOP, Opr::kBC, Opr::kNone, 12),
   /* 0xC2 */ Operation(Ins::kJP, Opr::kFlagNZ, Opr::kImm16, 16),
   /* 0xC3 */ Operation(Ins::kJP, Opr::kImm16, Opr::kNone, 16),
   /* 0xC4 */ Operation(Ins::kCALL, Opr::kFlagNZ, Opr::kImm16, 24),
   /* 0xC5 */ Operation(Ins::kPUSH, Opr::kBC, Opr::kNone, 16),
   /* 0xC6 */ Operation(Ins::kADD, Opr::kA, Opr::kImm8, 8),
   /* 0xC7 */ Operation(Ins::kRST, Opr::k00H, Opr::kNone, 16),
   /* 0xC8 */ Operation(Ins::kRET, Opr::kFlagZ, Opr::kNone, 20),
   /* 0xC9 */ Operation(Ins::kRET, Opr::kNone, Opr::kNone, 16),
   /* 0xCA */ Operation(Ins::kJP, Opr::kFlagZ, Opr::kImm16, 16),
   /* 0xCB */ Operation(Ins::kPREFIX, Opr::kCB, Opr::kNone, 4),
   /* 0xCC */ Operation(Ins::kCALL, Opr::kFlagZ, Opr::kImm16, 24),
   /* 0xCD */ Operation(Ins::kCALL, Opr::kImm16, Opr::kNone, 24),
   /* 0xCE */ Operation(Ins::kADC, Opr::kA, Opr::kImm8, 8),
   /* 0xCF */ Operation(Ins::kRST, Opr::k08H, Opr::kNone, 16),
   /* 0xD0 */ Operation(Ins::kRET, Opr::kFlagNC, Opr::kNone, 20),
   /* 0xD1 */ Operation(Ins::kPOP, Opr::kDE, Opr::kNone, 12),
   /* 0xD2 */ Operation(Ins::kJP, Opr::kFlagNC, Opr::kImm16, 16),
   /* 0xD3 */ Operation(Ins::kInvalid, Opr::kNone, Opr::kNone, 0),
   /* 0xD4 */ Operation(Ins::kCALL, Opr::kFlagNC, Opr::kImm16, 24),
   /* 0xD5 */ Operation(Ins::kPUSH, Opr::kDE, Opr::kNone, 16),
   /* 0xD6 */ Operation(Ins::kSUB, Opr::kImm8, Opr::kNone, 8),
   /* 0xD7 */ Operation(Ins::kRST, Opr::k10H, Opr::kNone, 16),
   /* 0xD8 */ Operation(Ins::kRET, Opr::kFlagC, Opr::kNone, 20),
   /* 0xD9 */ Operation(Ins::kRETI, Opr::kNone, Opr::kNone, 16),
   /* 0xDA */ Operation(Ins::kJP, Opr::kFlagC, Opr::kImm16, 16),
   /* 0xDB */ Operation(Ins::kInvalid, Opr::kNone, Opr::kNone, 0),
   /* 0xDC */ Operation(Ins::kCALL, Opr::kFlagC, Opr::kImm16, 24),
   /* 0xDD */ Operation(Ins::kInvalid, Opr::kNone, Opr::kNone, 0),
   /* 0xDE */ Operation(Ins::kSBC, Opr::kA, Opr::kImm8, 8),
   /* 0xDF */ Operation(Ins::kRST, Opr::k18H, Opr::kNone, 16),
   /* 0xE0 */ Operation(Ins::kLDH, Opr::kDrefImm8, Opr::kA, 12),
   /* 0xE1 */ Operation(Ins::kPOP, Opr::kHL, Opr::kNone, 12),
   /* 0xE2 */ Operation(Ins::kLD, Opr::kDrefC, Opr::kA, 8),
   /* 0xE3 */ Operation(Ins::kInvalid, Opr::kNone, Opr::kNone, 0),
   /* 0xE4 */ Operation(Ins::kInvalid, Opr::kNone, Opr::kNone, 0),
   /* 0xE5 */ Operation(Ins::kPUSH, Opr::kHL, Opr::kNone, 16),
   /* 0xE6 */ Operation(Ins::kAND, Opr::kImm8, Opr::kNone, 8),
   /* 0xE7 */ Operation(Ins::kRST, Opr::k20H, Opr::kNone, 16),
   /* 0xE8 */ Operation(Ins::kADD, Opr::kSP, Opr::kImm8Signed, 16),
   /* 0xE9 */ Operation(Ins::kJP, Opr::kHL, Opr::kNone, 4),
   /* 0xEA */ Operation(Ins::kLD, Opr::kDrefImm16, Opr::kA, 16),
   /* 0xEB */ Operation(Ins::kInvalid, Opr::kNone, Opr::kNone, 0),
   /* 0xEC */ Operation(Ins::kInvalid, Opr::kNone, Opr::kNone, 0),
   /* 0xED */ Operation(Ins::kInvalid, Opr::kNone, Opr::kNone, 0),
   /* 0xEE */ Operation(Ins::kXOR, Opr::kImm8, Opr::kNone, 8),
   /* 0xEF */ Operation(Ins::kRST, Opr::k28H, Opr::kNone, 16),
   /* 0xF0 */ Operation(Ins::kLDH, Opr::kA, Opr::kDrefImm8, 12),
   /* 0xF1 */ Operation(Ins::kPOP, Opr::kAF, Opr::kNone, 12),
   /* 0xF2 */ Operation(Ins::kLD, Opr::kA, Opr::kDrefC, 8),
   /* 0xF3 */ Operation(Ins::kDI, Opr::kNone, Opr::kNone, 4),
   /* 0xF4 */ Operation(Ins::kInvalid, Opr::kNone, Opr::kNone, 0),
   /* 0xF5 */ Operation(Ins::kPUSH, Opr::kAF, Opr::kNone, 16),
   /* 0xF6 */ Operation(Ins::kOR, Opr::kImm8, Opr::kNone, 8),
   /* 0xF7 */ Operation(Ins::kRST, Opr::k30H, Opr::kNone, 16),
   /* 0xF8 */ Operation(Ins::kLDHL, Opr::kSP, Opr::kImm8Signed, 12),
   /* 0xF9 */ Operation(Ins::kLD, Opr::kSP, Opr::kHL, 8),
   /* 0xFA */ Operation(Ins::kLD, Opr::kA, Opr::kDrefImm16, 16),
   /* 0xFB */ Operation(Ins::kEI, Opr::kNone, Opr::kNone, 4),
   /* 0xFC */ Operation(Ins::kInvalid, Opr::kNone, Opr::kNone, 0),
   /* 0xFD */ Operation(Ins::kInvalid, Opr::kNone, Opr::kNone, 0),
   /* 0xFE */ Operation(Ins::kCP, Opr::kImm8, Opr::kNone, 8),
   /* 0xFF */ Operation(Ins::kRST, Opr::k38H, Opr::kNone, 16),
};

const std::array<Operation, 256> kCBOperations = {
   /* 0x00 */ Operation(Ins::kRLC, Opr::kB, Opr::kNone, 8),
   /* 0x01 */ Operation(Ins::kRLC, Opr::kC, Opr::kNone, 8),
   /* 0x02 */ Operation(Ins::kRLC, Opr::kD, Opr::kNone, 8),
   /* 0x03 */ Operation(Ins::kRLC, Opr::kE, Opr::kNone, 8),
   /* 0x04 */ Operation(Ins::kRLC, Opr::kH, Opr::kNone, 8),
   /* 0x05 */ Operation(Ins::kRLC, Opr::kL, Opr::kNone, 8),
   /* 0x06 */ Operation(Ins::kRLC, Opr::kDrefHL, Opr::kNone, 16),
   /* 0x07 */ Operation(Ins::kRLC, Opr::kA, Opr::kNone, 8),
   /* 0x08 */ Operation(Ins::kRRC, Opr::kB, Opr::kNone, 8),
   /* 0x09 */ Operation(Ins::kRRC, Opr::kC, Opr::kNone, 8),
   /* 0x0A */ Operation(Ins::kRRC, Opr::kD, Opr::kNone, 8),
   /* 0x0B */ Operation(Ins::kRRC, Opr::kE, Opr::kNone, 8),
   /* 0x0C */ Operation(Ins::kRRC, Opr::kH, Opr::kNone, 8),
   /* 0x0D */ Operation(Ins::kRRC, Opr::kL, Opr::kNone, 8),
   /* 0x0E */ Operation(Ins::kRRC, Opr::kDrefHL, Opr::kNone, 16),
   /* 0x0F */ Operation(Ins::kRRC, Opr::kA, Opr::kNone, 8),
   /* 0x10 */ Operation(Ins::kRL, Opr::kB, Opr::kNone, 8),
   /* 0x11 */ Operation(Ins::kRL, Opr::kC, Opr::kNone, 8),
   /* 0x12 */ Operation(Ins::kRL, Opr::kD, Opr::kNone, 8),
   /* 0x13 */ Operation(Ins::kRL, Opr::kE, Opr::kNone, 8),
   /* 0x14 */ Operation(Ins::kRL, Opr::kH, Opr::kNone, 8),
   /* 0x15 */ Operation(Ins::kRL, Opr::kL, Opr::kNone, 8),
   /* 0x16 */ Operation(Ins::kRL, Opr::kDrefHL, Opr::kNone, 16),
   /* 0x17 */ Operation(Ins::kRL, Opr::kA, Opr::kNone, 8),
   /* 0x18 */ Operation(Ins::kRR, Opr::kB, Opr::kNone, 8),
   /* 0x19 */ Operation(Ins::kRR, Opr::kC, Opr::kNone, 8),
   /* 0x1A */ Operation(Ins::kRR, Opr::kD, Opr::kNone, 8),
   /* 0x1B */ Operation(Ins::kRR, Opr::kE, Opr::kNone, 8),
   /* 0x1C */ Operation(Ins::kRR, Opr::kH, Opr::kNone, 8),
   /* 0x1D */ Operation(Ins::kRR, Opr::kL, Opr::kNone, 8),
   /* 0x1E */ Operation(Ins::kRR, Opr::kDrefHL, Opr::kNone, 16),
   /* 0x1F */ Operation(Ins::kRR, Opr::kA, Opr::kNone, 8),
   /* 0x20 */ Operation(Ins::kSLA, Opr::kB, Opr::kNone, 8),
   /* 0x21 */ Operation(Ins::kSLA, Opr::kC, Opr::kNone, 8),
   /* 0x22 */ Operation(Ins::kSLA, Opr::kD, Opr::kNone, 8),
   /* 0x23 */ Operation(Ins::kSLA, Opr::kE, Opr::kNone, 8),
   /* 0x24 */ Operation(Ins::kSLA, Opr::kH, Opr::kNone, 8),
   /* 0x25 */ Operation(Ins::kSLA, Opr::kL, Opr::kNone, 8),
   /* 0x26 */ Operation(Ins::kSLA, Opr::kDrefHL, Opr::kNone, 16),
   /* 0x27 */ Operation(Ins::kSLA, Opr::kA, Opr::kNone, 8),
   /* 0x28 */ Operation(Ins::kSRA, Opr::kB, Opr::kNone, 8),
   /* 0x29 */ Operation(Ins::kSRA, Opr::kC, Opr::kNone, 8),
   /* 0x2A */ Operation(Ins::kSRA, Opr::kD, Opr::kNone, 8),
   /* 0x2B */ Operation(Ins::kSRA, Opr::kE, Opr::kNone, 8),
   /* 0x2C */ Operation(Ins::kSRA, Opr::kH, Opr::kNone, 8),
   /* 0x2D */ Operation(Ins::kSRA, Opr::kL, Opr::kNone, 8),
   /* 0x2E */ Operation(Ins::kSRA, Opr::kDrefHL, Opr::kNone, 16),
   /* 0x2F */ Operation(Ins::kSRA, Opr::kA, Opr::kNone, 8),
   /* 0x30 */ Operation(Ins::kSWAP, Opr::kB, Opr::kNone, 8),
   /* 0x31 */ Operation(Ins::kSWAP, Opr::kC, Opr::kNone, 8),
   /* 0x32 */ Operation(Ins::kSWAP, Opr::kD, Opr::kNone, 8),
   /* 0x33 */ Operation(Ins::kSWAP, Opr::kE, Opr::kNone, 8),
   /* 0x34 */ Operation(Ins::kSWAP, Opr::kH, Opr::kNone, 8),
   /* 0x35 */ Operation(Ins::kSWAP, Opr::kL, Opr::kNone, 8),
   /* 0x36 */ Operation(Ins::kSWAP, Opr::kDrefHL, Opr::kNone, 16),
   /* 0x37 */ Operation(Ins::kSWAP, Opr::kA, Opr::kNone, 8),
   /* 0x38 */ Operation(Ins::kSRL, Opr::kB, Opr::kNone, 8),
   /* 0x39 */ Operation(Ins::kSRL, Opr::kC, Opr::kNone, 8),
   /* 0x3A */ Operation(Ins::kSRL, Opr::kD, Opr::kNone, 8),
   /* 0x3B */ Operation(Ins::kSRL, Opr::kE, Opr::kNone, 8),
   /* 0x3C */ Operation(Ins::kSRL, Opr::kH, Opr::kNone, 8),
   /* 0x3D */ Operation(Ins::kSRL, Opr::kL, Opr::kNone, 8),
   /* 0x3E */ Operation(Ins::kSRL, Opr::kDrefHL, Opr::kNone, 16),
   /* 0x3F */ Operation(Ins::kSRL, Opr::kA, Opr::kNone, 8),
   /* 0x40 */ Operation(Ins::kBIT, Opr::k0, Opr::kB, 8),
   /* 0x41 */ Operation(Ins::kBIT, Opr::k0, Opr::kC, 8),
   /* 0x42 */ Operation(Ins::kBIT, Opr::k0, Opr::kD, 8),
   /* 0x43 */ Operation(Ins::kBIT, Opr::k0, Opr::kE, 8),
   /* 0x44 */ Operation(Ins::kBIT, Opr::k0, Opr::kH, 8),
   /* 0x45 */ Operation(Ins::kBIT, Opr::k0, Opr::kL, 8),
   /* 0x46 */ Operation(Ins::kBIT, Opr::k0, Opr::kDrefHL, 16),
   /* 0x47 */ Operation(Ins::kBIT, Opr::k0, Opr::kA, 8),
   /* 0x48 */ Operation(Ins::kBIT, Opr::k1, Opr::kB, 8),
   /* 0x49 */ Operation(Ins::kBIT, Opr::k1, Opr::kC, 8),
   /* 0x4A */ Operation(Ins::kBIT, Opr::k1, Opr::kD, 8),
   /* 0x4B */ Operation(Ins::kBIT, Opr::k1, Opr::kE, 8),
   /* 0x4C */ Operation(Ins::kBIT, Opr::k1, Opr::kH, 8),
   /* 0x4D */ Operation(Ins::kBIT, Opr::k1, Opr::kL, 8),
   /* 0x4E */ Operation(Ins::kBIT, Opr::k1, Opr::kDrefHL, 16),
   /* 0x4F */ Operation(Ins::kBIT, Opr::k1, Opr::kA, 8),
   /* 0x50 */ Operation(Ins::kBIT, Opr::k2, Opr::kB, 8),
   /* 0x51 */ Operation(Ins::kBIT, Opr::k2, Opr::kC, 8),
   /* 0x52 */ Operation(Ins::kBIT, Opr::k2, Opr::kD, 8),
   /* 0x53 */ Operation(Ins::kBIT, Opr::k2, Opr::kE, 8),
   /* 0x54 */ Operation(Ins::kBIT, Opr::k2, Opr::kH, 8),
   /* 0x55 */ Operation(Ins::kBIT, Opr::k2, Opr::kL, 8),
   /* 0x56 */ Operation(Ins::kBIT, Opr::k2, Opr::kDrefHL, 16),
   /* 0x57 */ Operation(Ins::kBIT, Opr::k2, Opr::kA, 8),
   /* 0x58 */ Operation(Ins::kBIT, Opr::k3, Opr::kB, 8),
   /* 0x59 */ Operation(Ins::kBIT, Opr::k3, Opr::kC, 8),
   /* 0x5A */ Operation(Ins::kBIT, Opr::k3, Opr::kD, 8),
   /* 0x5B */ Operation(Ins::kBIT, Opr::k3, Opr::kE, 8),
   /* 0x5C */ Operation(Ins::kBIT, Opr::k3, Opr::kH, 8),
   /* 0x5D */ Operation(Ins::kBIT, Opr::k3, Opr::kL, 8),
   /* 0x5E */ Operation(Ins::kBIT, Opr::k3, Opr::kDrefHL, 16),
   /* 0x5F */ Operation(Ins::kBIT, Opr::k3, Opr::kA, 8),
   /* 0x60 */ Operation(Ins::kBIT, Opr::k4, Opr::kB, 8),
   /* 0x61 */ Operation(Ins::kBIT, Opr::k4, Opr::kC, 8),
   /* 0x62 */ Operation(Ins::kBIT, Opr::k4, Opr::kD, 8),
   /* 0x63 */ Operation(Ins::kBIT, Opr::k4, Opr::kE, 8),
   /* 0x64 */ Operation(Ins::kBIT, Opr::k4, Opr::kH, 8),
   /* 0x65 */ Operation(Ins::kBIT, Opr::k4, Opr::kL, 8),
   /* 0x66 */ Operation(Ins::kBIT, Opr::k4, Opr::kDrefHL, 16),
   /* 0x67 */ Operation(Ins::kBIT, Opr::k4, Opr::kA, 8),
   /* 0x68 */ Operation(Ins::kBIT, Opr::k5, Opr::kB, 8),
   /* 0x69 */ Operation(Ins::kBIT, Opr::k5, Opr::kC, 8),
   /* 0x6A */ Operation(Ins::kBIT, Opr::k5, Opr::kD, 8),
   /* 0x6B */ Operation(Ins::kBIT, Opr::k5, Opr::kE, 8),
   /* 0x6C */ Operation(Ins::kBIT, Opr::k5, Opr::kH, 8),
   /* 0x6D */ Operation(Ins::kBIT, Opr::k5, Opr::kL, 8),
   /* 0x6E */ Operation(Ins::kBIT, Opr::k5, Opr::kDrefHL, 16),
   /* 0x6F */ Operation(Ins::kBIT, Opr::k5, Opr::kA, 8),
   /* 0x70 */ Operation(Ins::kBIT, Opr::k6, Opr::kB, 8),
   /* 0x71 */ Operation(Ins::kBIT, Opr::k6, Opr::kC, 8),
   /* 0x72 */ Operation(Ins::kBIT, Opr::k6, Opr::kD, 8),
   /* 0x73 */ Operation(Ins::kBIT, Opr::k6, Opr::kE, 8),
   /* 0x74 */ Operation(Ins::kBIT, Opr::k6, Opr::kH, 8),
   /* 0x75 */ Operation(Ins::kBIT, Opr::k6, Opr::kL, 8),
   /* 0x76 */ Operation(Ins::kBIT, Opr::k6, Opr::kDrefHL, 16),
   /* 0x77 */ Operation(Ins::kBIT, Opr::k6, Opr::kA, 8),
   /* 0x78 */ Operation(Ins::kBIT, Opr::k7, Opr::kB, 8),
   /* 0x79 */ Operation(Ins::kBIT, Opr::k7, Opr::kC, 8),
   /* 0x7A */ Operation(Ins::kBIT, Opr::k7, Opr::kD, 8),
   /* 0x7B */ Operation(Ins::kBIT, Opr::k7, Opr::kE, 8),
   /* 0x7C */ Operation(Ins::kBIT, Opr::k7, Opr::kH, 8),
   /* 0x7D */ Operation(Ins::kBIT, Opr::k7, Opr::kL, 8),
   /* 0x7E */ Operation(Ins::kBIT, Opr::k7, Opr::kDrefHL, 16),
   /* 0x7F */ Operation(Ins::kBIT, Opr::k7, Opr::kA, 8),
   /* 0x80 */ Operation(Ins::kRES, Opr::k0, Opr::kB, 8),
   /* 0x81 */ Operation(Ins::kRES, Opr::k0, Opr::kC, 8),
   /* 0x82 */ Operation(Ins::kRES, Opr::k0, Opr::kD, 8),
   /* 0x83 */ Operation(Ins::kRES, Opr::k0, Opr::kE, 8),
   /* 0x84 */ Operation(Ins::kRES, Opr::k0, Opr::kH, 8),
   /* 0x85 */ Operation(Ins::kRES, Opr::k0, Opr::kL, 8),
   /* 0x86 */ Operation(Ins::kRES, Opr::k0, Opr::kDrefHL, 16),
   /* 0x87 */ Operation(Ins::kRES, Opr::k0, Opr::kA, 8),
   /* 0x88 */ Operation(Ins::kRES, Opr::k1, Opr::kB, 8),
   /* 0x89 */ Operation(Ins::kRES, Opr::k1, Opr::kC, 8),
   /* 0x8A */ Operation(Ins::kRES, Opr::k1, Opr::kD, 8),
   /* 0x8B */ Operation(Ins::kRES, Opr::k1, Opr::kE, 8),
   /* 0x8C */ Operation(Ins::kRES, Opr::k1, Opr::kH, 8),
   /* 0x8D */ Operation(Ins::kRES, Opr::k1, Opr::kL, 8),
   /* 0x8E */ Operation(Ins::kRES, Opr::k1, Opr::kDrefHL, 16),
   /* 0x8F */ Operation(Ins::kRES, Opr::k1, Opr::kA, 8),
   /* 0x90 */ Operation(Ins::kRES, Opr::k2, Opr::kB, 8),
   /* 0x91 */ Operation(Ins::kRES, Opr::k2, Opr::kC, 8),
   /* 0x92 */ Operation(Ins::kRES, Opr::k2, Opr::kD, 8),
   /* 0x93 */ Operation(Ins::kRES, Opr::k2, Opr::kE, 8),
   /* 0x94 */ Operation(Ins::kRES, Opr::k2, Opr::kH, 8),
   /* 0x95 */ Operation(Ins::kRES, Opr::k2, Opr::kL, 8),
   /* 0x96 */ Operation(Ins::kRES, Opr::k2, Opr::kDrefHL, 16),
   /* 0x97 */ Operation(Ins::kRES, Opr::k2, Opr::kA, 8),
   /* 0x98 */ Operation(Ins::kRES, Opr::k3, Opr::kB, 8),
   /* 0x99 */ Operation(Ins::kRES, Opr::k3, Opr::kC, 8),
   /* 0x9A */ Operation(Ins::kRES, Opr::k3, Opr::kD, 8),
   /* 0x9B */ Operation(Ins::kRES, Opr::k3, Opr::kE, 8),
   /* 0x9C */ Operation(Ins::kRES, Opr::k3, Opr::kH, 8),
   /* 0x9D */ Operation(Ins::kRES, Opr::k3, Opr::kL, 8),
   /* 0x9E */ Operation(Ins::kRES, Opr::k3, Opr::kDrefHL, 16),
   /* 0x9F */ Operation(Ins::kRES, Opr::k3, Opr::kA, 8),
   /* 0xA0 */ Operation(Ins::kRES, Opr::k4, Opr::kB, 8),
   /* 0xA1 */ Operation(Ins::kRES, Opr::k4, Opr::kC, 8),
   /* 0xA2 */ Operation(Ins::kRES, Opr::k4, Opr::kD, 8),
   /* 0xA3 */ Operation(Ins::kRES, Opr::k4, Opr::kE, 8),
   /* 0xA4 */ Operation(Ins::kRES, Opr::k4, Opr::kH, 8),
   /* 0xA5 */ Operation(Ins::kRES, Opr::k4, Opr::kL, 8),
   /* 0xA6 */ Operation(Ins::kRES, Opr::k4, Opr::kDrefHL, 16),
   /* 0xA7 */ Operation(Ins::kRES, Opr::k4, Opr::kA, 8),
   /* 0xA8 */ Operation(Ins::kRES, Opr::k5, Opr::kB, 8),
   /* 0xA9 */ Operation(Ins::kRES, Opr::k5, Opr::kC, 8),
   /* 0xAA */ Operation(Ins::kRES, Opr::k5, Opr::kD, 8),
   /* 0xAB */ Operation(Ins::kRES, Opr::k5, Opr::kE, 8),
   /* 0xAC */ Operation(Ins::kRES, Opr::k5, Opr::kH, 8),
   /* 0xAD */ Operation(Ins::kRES, Opr::k5, Opr::kL, 8),
   /* 0xAE */ Operation(Ins::kRES, Opr::k5, Opr::kDrefHL, 16),
   /* 0xAF */ Operation(Ins::kRES, Opr::k5, Opr::kA, 8),
   /* 0xB0 */ Operation(Ins::kRES, Opr::k6, Opr::kB, 8),
   /* 0xB1 */ Operation(Ins::kRES, Opr::k6, Opr::kC, 8),
   /* 0xB2 */ Operation(Ins::kRES, Opr::k6, Opr::kD, 8),
   /* 0xB3 */ Operation(Ins::kRES, Opr::k6, Opr::kE, 8),
   /* 0xB4 */ Operation(Ins::kRES, Opr::k6, Opr::kH, 8),
   /* 0xB5 */ Operation(Ins::kRES, Opr::k6, Opr::kL, 8),
   /* 0xB6 */ Operation(Ins::kRES, Opr::k6, Opr::kDrefHL, 16),
   /* 0xB7 */ Operation(Ins::kRES, Opr::k6, Opr::kA, 8),
   /* 0xB8 */ Operation(Ins::kRES, Opr::k7, Opr::kB, 8),
   /* 0xB9 */ Operation(Ins::kRES, Opr::k7, Opr::kC, 8),
   /* 0xBA */ Operation(Ins::kRES, Opr::k7, Opr::kD, 8),
   /* 0xBB */ Operation(Ins::kRES, Opr::k7, Opr::kE, 8),
   /* 0xBC */ Operation(Ins::kRES, Opr::k7, Opr::kH, 8),
   /* 0xBD */ Operation(Ins::kRES, Opr::k7, Opr::kL, 8),
   /* 0xBE */ Operation(Ins::kRES, Opr::k7, Opr::kDrefHL, 16),
   /* 0xBF */ Operation(Ins::kRES, Opr::k7, Opr::kA, 8),
   /* 0xC0 */ Operation(Ins::kSET, Opr::k0, Opr::kB, 8),
   /* 0xC1 */ Operation(Ins::kSET, Opr::k0, Opr::kC, 8),
   /* 0xC2 */ Operation(Ins::kSET, Opr::k0, Opr::kD, 8),
   /* 0xC3 */ Operation(Ins::kSET, Opr::k0, Opr::kE, 8),
   /* 0xC4 */ Operation(Ins::kSET, Opr::k0, Opr::kH, 8),
   /* 0xC5 */ Operation(Ins::kSET, Opr::k0, Opr::kL, 8),
   /* 0xC6 */ Operation(Ins::kSET, Opr::k0, Opr::kDrefHL, 16),
   /* 0xC7 */ Operation(Ins::kSET, Opr::k0, Opr::kA, 8),
   /* 0xC8 */ Operation(Ins::kSET, Opr::k1, Opr::kB, 8),
   /* 0xC9 */ Operation(Ins::kSET, Opr::k1, Opr::kC, 8),
   /* 0xCA */ Operation(Ins::kSET, Opr::k1, Opr::kD, 8),
   /* 0xCB */ Operation(Ins::kSET, Opr::k1, Opr::kE, 8),
   /* 0xCC */ Operation(Ins::kSET, Opr::k1, Opr::kH, 8),
   /* 0xCD */ Operation(Ins::kSET, Opr::k1, Opr::kL, 8),
   /* 0xCE */ Operation(Ins::kSET, Opr::k1, Opr::kDrefHL, 16),
   /* 0xCF */ Operation(Ins::kSET, Opr::k1, Opr::kA, 8),
   /* 0xD0 */ Operation(Ins::kSET, Opr::k2, Opr::kB, 8),
   /* 0xD1 */ Operation(Ins::kSET, Opr::k2, Opr::kC, 8),
   /* 0xD2 */ Operation(Ins::kSET, Opr::k2, Opr::kD, 8),
   /* 0xD3 */ Operation(Ins::kSET, Opr::k2, Opr::kE, 8),
   /* 0xD4 */ Operation(Ins::kSET, Opr::k2, Opr::kH, 8),
   /* 0xD5 */ Operation(Ins::kSET, Opr::k2, Opr::kL, 8),
   /* 0xD6 */ Operation(Ins::kSET, Opr::k2, Opr::kDrefHL, 16),
   /* 0xD7 */ Operation(Ins::kSET, Opr::k2, Opr::kA, 8),
   /* 0xD8 */ Operation(Ins::kSET, Opr::k3, Opr::kB, 8),
   /* 0xD9 */ Operation(Ins::kSET, Opr::k3, Opr::kC, 8),
   /* 0xDA */ Operation(Ins::kSET, Opr::k3, Opr::kD, 8),
   /* 0xDB */ Operation(Ins::kSET, Opr::k3, Opr::kE, 8),
   /* 0xDC */ Operation(Ins::kSET, Opr::k3, Opr::kH, 8),
   /* 0xDD */ Operation(Ins::kSET, Opr::k3, Opr::kL, 8),
   /* 0xDE */ Operation(Ins::kSET, Opr::k3, Opr::kDrefHL, 16),
   /* 0xDF */ Operation(Ins::kSET, Opr::k3, Opr::kA, 8),
   /* 0xE0 */ Operation(Ins::kSET, Opr::k4, Opr::kB, 8),
   /* 0xE1 */ Operation(Ins::kSET, Opr::k4, Opr::kC, 8),
   /* 0xE2 */ Operation(Ins::kSET, Opr::k4, Opr::kD, 8),
   /* 0xE3 */ Operation(Ins::kSET, Opr::k4, Opr::kE, 8),
   /* 0xE4 */ Operation(Ins::kSET, Opr::k4, Opr::kH, 8),
   /* 0xE5 */ Operation(Ins::kSET, Opr::k4, Opr::kL, 8),
   /* 0xE6 */ Operation(Ins::kSET, Opr::k4, Opr::kDrefHL, 16),
   /* 0xE7 */ Operation(Ins::kSET, Opr::k4, Opr::kA, 8),
   /* 0xE8 */ Operation(Ins::kSET, Opr::k5, Opr::kB, 8),
   /* 0xE9 */ Operation(Ins::kSET, Opr::k5, Opr::kC, 8),
   /* 0xEA */ Operation(Ins::kSET, Opr::k5, Opr::kD, 8),
   /* 0xEB */ Operation(Ins::kSET, Opr::k5, Opr::kE, 8),
   /* 0xEC */ Operation(Ins::kSET, Opr::k5, Opr::kH, 8),
   /* 0xED */ Operation(Ins::kSET, Opr::k5, Opr::kL, 8),
   /* 0xEE */ Operation(Ins::kSET, Opr::k5, Opr::kDrefHL, 16),
   /* 0xEF */ Operation(Ins::kSET, Opr::k5, Opr::kA, 8),
   /* 0xF0 */ Operation(Ins::kSET, Opr::k6, Opr::kB, 8),
   /* 0xF1 */ Operation(Ins::kSET, Opr::k6, Opr::kC, 8),
   /* 0xF2 */ Operation(Ins::kSET, Opr::k6, Opr::kD, 8),
   /* 0xF3 */ Operation(Ins::kSET, Opr::k6, Opr::kE, 8),
   /* 0xF4 */ Operation(Ins::kSET, Opr::k6, Opr::kH, 8),
   /* 0xF5 */ Operation(Ins::kSET, Opr::k6, Opr::kL, 8),
   /* 0xF6 */ Operation(Ins::kSET, Opr::k6, Opr::kDrefHL, 16),
   /* 0xF7 */ Operation(Ins::kSET, Opr::k6, Opr::kA, 8),
   /* 0xF8 */ Operation(Ins::kSET, Opr::k7, Opr::kB, 8),
   /* 0xF9 */ Operation(Ins::kSET, Opr::k7, Opr::kC, 8),
   /* 0xFA */ Operation(Ins::kSET, Opr::k7, Opr::kD, 8),
   /* 0xFB */ Operation(Ins::kSET, Opr::k7, Opr::kE, 8),
   /* 0xFC */ Operation(Ins::kSET, Opr::k7, Opr::kH, 8),
   /* 0xFD */ Operation(Ins::kSET, Opr::k7, Opr::kL, 8),
   /* 0xFE */ Operation(Ins::kSET, Opr::k7, Opr::kDrefHL, 16),
   /* 0xFF */ Operation(Ins::kSET, Opr::k7, Opr::kA, 8),
};

} // namespace

} // namespace GBC

#endif
