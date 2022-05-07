LLVM: 1
TTT:       2
TEMP@: b   integer  1
I: 0
TTT:       2
TEMP@: a   integer  0
I: 1
Line: 23  No declaration of v
line: 23 No declaration of variable: v
Line:23    Cannot assign values to variables of different types
; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(i8*, ...)

define i32 @main() {
  %1 = alloca i32
  store i32 0, i32* %1
  %2 = alloca i32
  store i32 0, i32* %2
  %3 = alloca i32
  store i32 0, i32* %3
  %4 = alloca i32
  store i32 0, i32* %4
  %5 = alloca i32
  store i32 0, i32* %5
  %6 = alloca float
  store float 0.000000e+00, float* %6
  %7 = alloca float
  store float 0.000000e+00, float* %7
  %8 = alloca i8
  store i8 0, i8* %8
  %9 = alloca [9 x i32]
  store i32 1, i32* %2
  %10 = getelementptr [9 x i32], [9 x i32]* %9, i32 0, i32 8
  store i32 2, i32* %10
  %11 = alloca i32
  %12 = load i32, i32* %2
  store i32 %12, i32* %11
  %13 = alloca i32
  %14 = load i32, i32* %1
  store i32 %14, i32* %13
  %15 = load i32, i32* %1
  %16 = alloca i32
  store i32 2, i32* %16
  store i32 7, i32* %3
  %17 = load i32, i32* %13
  %18 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %17)
  %19 = load i32, i32* %3
  %20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @1, i32 0, i32 0), i32 %19)
  store i32 5, i32* %1
  %21 = alloca i32
  store i32 7, i32* %21
  %22 = load i32, i32* %21
  store i32 %22, i32* %4
  %23 = load i32, i32* %1
  %24 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @2, i32 0, i32 0), i32 %23)
  ret i32 0
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
