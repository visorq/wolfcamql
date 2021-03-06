#ifndef cg_q3mme_camera_h_included
#define cg_q3mme_camera_h_included

#include "../qcommon/q_shared.h"
#include "../game/bg_xmlparser.h"
#include "cg_local.h"
#include "cg_q3mme_math.h"


typedef struct demoCameraPoint_s {
	struct			demoCameraPoint_s *next, *prev;
	vec3_t			origin, angles;
	float			fov;
	int				time, flags;
	float			len;
} demoCameraPoint_t;

typedef struct demoMain_s {
	int serverTime;

    struct {
		// selects start and end points for /q3mmecamera shift
        int                     start, end;
        int                     target, flags;
        int                     shiftWarn;
        float           timeShift;
        float           fov;
		// wolfcamql this is lke cg_cameraQue
        // qboolean        locked;
        vec3_t          angles, origin, velocity;
        demoCameraPoint_t *points;
        posInterpolate_t        smoothPos;
        angleInterpolate_t      smoothAngles;
    } camera;

	struct {
		int time;
		float fraction;
	} play;

	vec3_t viewOrigin;
	vec3_t viewAngles;
	//vec3_t viewFov;
	float viewFov;

} demoMain_t;

extern demoMain_t demo;

//qboolean cameraOriginAt (int time, float timeFraction, vec3_t origin);
//qboolean cameraAnglesAt (int time, float timeFraction, vec3_t angles);
//qboolean cameraFovAt (int time, float timeFraction, float *fov);

demoCameraPoint_t *CG_Q3mmeCameraPointAdd (int time, int flags);
qboolean CG_Q3mmeCameraOriginAt (int time, float timeFraction, vec3_t origin);
qboolean CG_Q3mmeCameraAnglesAt (int time, float timeFraction, vec3_t angles);
qboolean CG_Q3mmeCameraFovAt (int time, float timeFraction, float *fov);
void CG_Q3mmeCameraDrawPath (demoCameraPoint_t *point, const vec4_t color);


void CG_Q3mmeDemoCameraCommand_f (void);
void CG_Q3mmeCameraSave (fileHandle_t fileHandle);
qboolean CG_Q3mmeCameraParse (BG_XMLParse_t *parse, const struct BG_XMLParseBlock_s *fromBlock, void *data);
void CG_Q3mmeCameraResetInternalLengths (void);

#endif  // cg_q3mme_camera_h_included
