Line:16    Cannot assign values to variables of different types
; ModuleID = 'main'
source_filename = "main"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@0 = private unnamed_addr constant [5 x i8] c"%lf\0A\00", align 1
@1 = private unnamed_addr constant [5 x i8] c"%lf\0A\00", align 1

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
  %1 = alloca i32
  store i32 0, i32* %1
  %2 = alloca i32
  store i32 0, i32* %2
  %3 = alloca i32
  store i32 0, i32* %3
  %4 = alloca double
  store double 0.000000e+00, double* %4
  %5 = alloca [60 x i32]
  %6 = bitcast [60 x i32]* %5 to i32*
  store i32 2, i32* %6
  %7 = getelementptr [60 x i32], [60 x i32]* %5, i32 0, i32 1
  store i32 1, i32* %7
  %8 = getelementptr [60 x i32], [60 x i32]* %5, i32 0, i32 1
  %9 = load i32, i32* %8
  %10 = add i32 %9, 4
  store i32 %10, i32* %1
  %11 = load i32, i32* %1
  %12 = sitofp i32 %11 to double
  %13 = fdiv double %12, 0x3FB99999A0000000
  %14 = load double, double* %4
  %15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @0, i32 0, i32 0), double %14)
  %16 = load i32, i32* %1
  %17 = sitofp i32 %16 to double
  %18 = fmul double %17, 0x3FF3333340000000
  %19 = fadd double 3.000000e+00, %18
  %20 = fsub double %19, 1.500000e+00
  store double %20, double* %4
  %21 = load double, double* %4
  %22 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @1, i32 0, i32 0), double %21)
  ret i32 0
}

; Function Attrs: nounwind
declare void @llvm.stackprotector(i8*, i8**) #0

attributes #0 = { nounwind }
