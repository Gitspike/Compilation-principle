redeclaration of n3
; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [6 x i8] c"%d%d\0A\00", align 1

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
  %1 = alloca i32
  store i32 0, i32* %1
  store i32 4, i32* %1
  %2 = alloca i32
  store i32 2, i32* %2
  %3 = alloca i32
  store i32 3, i32* %3
  %4 = alloca i32
  store i32 0, i32* %4
  %5 = alloca i32
  store i32 4, i32* %5
  %6 = load i32, i32* %5
  %7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %6)
  %8 = alloca i32
  store i32 3, i32* %8
  %9 = load i32, i32* %8
  %10 = mul i32 %9, 2
  %11 = alloca i32
  store i32 %10, i32* %11
  %12 = load i32, i32* %11
  store i32 %12, i32* %2
  %13 = load i32, i32* %11
  %14 = load i32, i32* %1
  %15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @1, i32 0, i32 0), i32 %13, i32 %14)
  ret i32 0
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
