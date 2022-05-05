; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@3 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

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
  %9 = alloca [12 x i32]
  store i32 1, i32* %2
  %10 = load i32, i32* %1
  %11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %10)
  %12 = load i32, i32* %2
  %13 = add i32 %12, 1
  %14 = getelementptr [12 x i32], [12 x i32]* %9, i32 0, i32 5
  store i32 %13, i32* %14
  %15 = load i32, i32* %2
  %16 = add i32 %15, 1
  %17 = getelementptr [12 x i32], [12 x i32]* %9, i32 0, i32 5
  %18 = load i32, i32* %17
  %19 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @1, i32 0, i32 0), i32 %18)
  store i32 2, i32* %1
  %20 = load i32, i32* %1
  %21 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @2, i32 0, i32 0), i32 %20)
  %22 = bitcast [12 x i32]* %9 to i32*
  %23 = alloca i32
  %24 = load i32, i32* %22
  store i32 %24, i32* %23
  %25 = alloca i32
  store i32 0, i32* %25
  %26 = load i32, i32* %1
  store i32 %26, i32* %25
  %27 = alloca i32
  store i32 2, i32* %27
  %28 = alloca i32
  store i32 0, i32* %28
  store i32 7, i32* %25
  %29 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @3, i32 0, i32 0), i32 7)
  %30 = alloca i32
  store i32 7, i32* %30
  %31 = load i32, i32* %30
  store i32 %31, i32* %4
  ret i32 0
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
