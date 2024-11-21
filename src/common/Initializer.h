#pragma once

class Initializer
{
public:
	Initializer(auto lambda) { lambda(); }
};

