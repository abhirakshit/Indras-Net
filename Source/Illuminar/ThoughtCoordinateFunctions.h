// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ThoughtCoordinateFunctions.generated.h"

/**
 * 
 */
UCLASS()
class ILLUMINAR_API UThoughtCoordinateFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "Math|Sphere")
		static FVector CalculateIntersectionPoint(const FVector& SphereCenter, float SphereRadius, const FVector& PointInsideSphere, const FVector& DirectionVector, bool& bSuccessful);

	UFUNCTION(BlueprintPure, Category = "Math|Sphere")
		static FVector CalculateReflection(const FVector& SphereCenter, float SphereRadius, const FVector& PointInsideSphere, const FVector& DirectionVector, float ReflectionCoefficient, bool& bSuccessful, FVector& ReflectedDirection);
};