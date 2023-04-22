// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SortingArray.generated.h"

/**
 * 
 */
UCLASS()
class ILLUMINAR_API USortingArray : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Sorting Functions")            // Expose node to blueprints using 'BlueprintCallable', 'Category' gives your function a "searchable" header category in BPs
        static void  Integer_Sort(UPARAM(ref) TArray <int32>& Array_To_Sort, bool Descending, TArray <int32>& Sorted_Array);   // 'static' so node is accessible anywhere
    // 'UPARAM' makes argument an exposed input pin
    UFUNCTION(BlueprintCallable, Category = "Sorting Functions")                                                                //  'UPARAM(ref)' passes argument by reference
        static void  Float_Sort(UPARAM(ref) TArray <float>& Array_To_Sort, bool Descending, TArray <float>& Sorted_Array);

    UFUNCTION(BlueprintCallable, Category = "Sorting Functions")
        static void  String_Sort(UPARAM(ref) TArray <FString>& Array_To_Sort, bool Descending, TArray <FString>& Sorted_Array);

    UFUNCTION(BlueprintCallable, Category = "Sorting Functions")
        static void  Sort_Map_By_Value(UPARAM(ref) TMap<FString, float>& Map_To_Sort, bool Descending, TMap <FString, float>& Sorted_Map);

	
};
