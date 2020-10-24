/* Enter appropriate values for predefined macros */
#define TIMING_EVENT_PERIOD_MS 		0;
#define TIRE_CIRCUMFERENCE_KM_FL 	0;
#define TIRE_CIRCUMFERENCE_KM_FR 	0;
#define TIRE_CIRCUMFERENCE_KM_RL 	0;
#define TIRE_CIRCUMFERENCE_KM_RR 	0;

float TireVelocityKmph[4] = {0};
int TireRevolutionCounter[4] = {0};
float TireCircumferenceKm[4] = {TIRE_CIRCUMFERENCE_KM_FL, TIRE_CIRCUMFERENCE_KM_FR, TIRE_CIRCUMFERENCE_KM_RL, TIRE_CIRCUMFERENCE_KM_RR};

float* RETURN_KMPH_FROM_REV(void);
int business_logic_change_name(int TirePosition);

float* RETURN_KMPH_FROM_REV(void)
{
	for (int TirePosition = 0; TirePosition < 4; TirePosition++)
	{
		business_logic_change_name(TirePosition);
	}

	return &TireVelocityKmph;
}

int business_logic_change_name(int TirePosition)
{
	if (IS_REV_VALID_TIRE(TirePosition) == 1)
	{
		TireVelocityKmph[TirePosition] = TireCircumferenceKm[TirePosition] * 3600000 / (TireRevolutionCounter[TirePosition] * TIMING_EVENT_PERIOD_MS);
		TireRevolutionCounter[TirePosition] = 0;
	}

	else
	{
		TireRevolutionCounter[TirePosition]++;

		if (TireRevolutionCounter[TirePosition] > 216)
		{
			TireRevolutionCounter[TirePosition] = 0;
		}

		TireVelocityKmph[TirePosition] = 0;
	}
}
