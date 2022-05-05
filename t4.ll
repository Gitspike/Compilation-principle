; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @printf(i8*, ...)

define i32 @main() {
  %1 = alloca i32
  store i32 0, i32* %1
  %2 = alloca i32
  store i32 0, i32* %2
  %3 = alloca i32
  store i32 0, i32* %3
  %4 = alloca [9 x i32]
  store i32 2, i32* %1
  %5 = getelementptr [9 x i32], [9 x i32]* %4, i32 0, i32 2
  store i32 4, i32* %5
  store i32 1, i32* %2
  %6 = alloca i32
  %7 = load i32, i32* %2
  store i32 %7, i32* %6
  %8 = alloca i32
  store i32 0, i32* %8
  store i32 5, i32* %6
  %9 = load i32, i32* %6
  %10 = alloca i32
  store i32 %9, i32* %10
  %11 = bitcast [9 x i32]* %4 to i32*
  %12 = alloca i32
  %13 = load i32, i32* %11
  store i32 %13, i32* %12
  %14 = alloca i32
  store i32 0, i32* %14
  store i32 5, i32* %12
  %15 = load i32, i32* %12
  store i32 %15, i32* %10
  %16 = load i32, i32* %10
  store i32 %16, i32* %3
  %17 = load i32, i32* %3
  %18 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %17)
  ret i32 0
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
