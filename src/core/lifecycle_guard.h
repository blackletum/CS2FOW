#pragma once

#include <chrono>
#include <cstdint>

namespace cs2fow
{

struct lifecycle_key
{
	bool has_controller {};
	bool hltv {};
	int pawn_entity {-1};
	uint8_t team {};
	bool alive {};
	bool spawning {};
	int32_t death_flags {};
	bool has_death_info {};
	float death_time {};
	float death_info_time {};
};

struct lifecycle_guard
{
	lifecycle_key key;
	std::chrono::steady_clock::time_point fail_open_until {};
	bool initialized {};
};

inline bool lifecycle_changed(const lifecycle_key &left, const lifecycle_key &right)
{
	return left.has_controller != right.has_controller
		|| left.hltv != right.hltv
		|| left.pawn_entity != right.pawn_entity
		|| left.team != right.team
		|| left.alive != right.alive
		|| left.spawning != right.spawning
		|| left.death_flags != right.death_flags
		|| left.has_death_info != right.has_death_info
		|| left.death_time != right.death_time
		|| left.death_info_time != right.death_info_time;
}

inline void update_lifecycle_guard(lifecycle_guard &guard, const lifecycle_key &key, bool stable,
	std::chrono::steady_clock::time_point now, std::chrono::milliseconds grace)
{
	if (!guard.initialized || lifecycle_changed(guard.key, key) || !stable)
	{
		guard.fail_open_until = now + grace;
	}
	guard.key = key;
	guard.initialized = true;
}

inline bool lifecycle_allows_hiding(const lifecycle_guard &guard, std::chrono::steady_clock::time_point now)
{
	return guard.initialized && now >= guard.fail_open_until;
}

} // namespace cs2fow
