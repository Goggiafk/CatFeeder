// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/UserWidget.h"
#include "CatFeederPawn.generated.h"

UCLASS()
class CATFEEDER_API ACatFeederPawn : public APawn
{
	GENERATED_BODY()

	
public:
	// Sets default values for this pawn's properties
	ACatFeederPawn();

	UPROPERTY(EditAnywhere, Category = "UI_HUD")
		TSubclassOf<UUserWidget> Cat_Hud;
	UUserWidget* Cat_Hud_Widget;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int PickedFoodType = 0;

	UFUNCTION(BlueprintCallable)
		void SetFoodType(int foodId);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MovePosition(float position);
};
