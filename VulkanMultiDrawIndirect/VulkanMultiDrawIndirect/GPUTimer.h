
#pragma once
#include "VulkanHelpers.h"
#include <map>

class GPUTimer
{
	struct ProfileData
	{
		uint8_t currentFrame;
		uint8_t currentTimeFrame;
		uint32_t* start;
		uint32_t* end;

	};

public:
	GPUTimer(VkDevice device, uint8_t queryLatency);
	~GPUTimer();

	const void Start(VkCommandBuffer& buffer, VkPipelineStageFlagBits flags, uint64_t GUID);
	const void End(VkCommandBuffer& buffer, VkPipelineStageFlagBits flags, uint64_t GUID);
	const double GetTime(uint64_t GUID);
	const double GetAverageTimePerSecond(uint64_t GUID);

private:
	VkDevice _device;
	VkQueryPool _pool;
	uint32_t _maxCounters;
	uint8_t _queryLatency;
	std::map<uint64_t, ProfileData> _timers;
};
