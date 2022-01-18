#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include "luawrap_toy.h"

#include "luawrap_timer_manager.h"
#include "luawrap_geometry_builder.h"
#include "luawrap_script_runner.h"
#include "luawrap_input_manager.h"
#include "luawrap_camera.h"
#include "luawrap_camera_manager.h"
#include "luawrap_camera_controller.h"
#include "luawrap_render_manager.h"

#include "luawrap_app.h"

#include "global_app.h"


static void luawrap_toy(sol::table& m) {
	luawrap_timer_manager(m);
	luawrap_input_manager(m);
	luawrap_camera(m);
	luawrap_camera_manager(m);
	luawrap_camera_controller(m);
	luawrap_render_manager(m);

	luawrap_geometry_builder(m);

	luawrap_script_runner(m);

	luawrap_app(m);
}

int luaopen_toy(lua_State * L) {
	sol::state_view lua(L);
	sol::table m = lua.create_table();

	luawrap_toy(m);

	m["app"] = g_app;
	m.set_function("get_app", []() {
		return g_app;
	});

	sol::stack::push(lua, m);
	return 1;
}
