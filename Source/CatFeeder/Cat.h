// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Cat.generated.h"

UCLASS()
class CATFEEDER_API ACat : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACat();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Saturation;

	UPROPERTY(EditAnywhere)
	float Saturation_Threshold = 3.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int FoodType = 0;

	UFUNCTION(BlueprintCallable)
		void SetFoodType(int type);
	
	bool bDead;
	
	// UPROPERTY(EditAnywhere, Category = "UI_HUD")
	// 	TSubclassOf<UUserWidget> Cat_Saturation_Widget_Class;
	// UUserWidget* Cat_Saturation_Widget;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
