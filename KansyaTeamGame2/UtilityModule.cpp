//�d��
// v = gt  v = v0 + gt
// v���x g�d�� t���� v0�����x
bool Gravity(float *v0)
{
	float g = 9.8f;
	float v = 0.0f;
	float t_time = 0;
	float t = 0;

	t_time++;

	t = t_time / 60;

	if (*v0 == 0)
	{
		v = g;
	}
	else
	{
		v = *v0 + (g * t);
	}

	return v;
}