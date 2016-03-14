
void initialise(int &a, int &b, int numbermap[])
{
	for(int i=0;i<10;i++)
	{
		if(numbermap[i] == '\0')
		{
			a = i;
			break;
		}
	}

	for(int i=0;i<10;i++)
	{
		if(numbermap[i] == '\0' and i!=a)
		{
			b = i;
			break;
		}
	}
}