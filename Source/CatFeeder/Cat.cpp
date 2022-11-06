// Fill out your copyright notice in the Description page of Project Settings.


#include "Cat.h"

#include "Blueprint/UserWidget.h"

// Sets default values
ACat::ACat()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Saturation = 100;
	bDead = false;
}

// Called when the game starts or when spawned
void ACat::BeginPlay()
{
	Super::BeginPlay();
	// if(Cat_Saturation_Widget_Class != nullptr)
	// {
	// 	Cat_Saturation_Widget = CreateWidget(GetWorld(), Cat_Saturation_Widget_Class);
	// 	Cat_Saturation_Widget->AddToViewport();
	// }
}

// Called every frame
void ACat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Saturation -= DeltaTime * Saturation_Threshold;
	
	if(Saturation <= 0)
	{
		if(!bDead)
		{
			bDead = true;

			this->Destroy();
		}
	}
}

// Called to bind functionality to input
void ACat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

