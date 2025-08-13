/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __VMS_COM_H
#define __VMS_COM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Private defines -----------------------------------------------------------*/
#define PELCO_D_SYNC        0xFF
#define PELCO_D_LEN                           7
#define PELCO_D_CS_IDX_S                      1
#define PELCO_D_CS_IDX_E                      (len - 1)

#define SW_SYNC        0xFF
#define SW_LEN         13
#define SW_CS_IDX_S    0
#define SW_CS_IDX_E    (len - 1)

#define C_PT_STOP           0x00
#define C_PT_RIGHT          0x04
#define C_PT_LEFT           0x02
#define C_PT_UP             0x08
#define C_PT_DOWN           0x10
#define C_PT_UP_LEFT        0x0C
#define C_PT_UP_RIGHT       0x0A
#define C_PT_DOWN_RIGHT     0x12
#define C_PT_DOWN_LEFT      0x14

#define COM_FUNCTION				0x01

//**************** 기능 ********************
#define C_PT_PRESET_SAVE			          0x03
#define C_PT_PRESET_CLR			            0x05
#define C_PT_PRESET_GO			            0x07

#define C_PT_RIGHT_UP_STEP              0x65    //상대 위치 제어
#define C_PT_LEFT_UP_STEP               0x67    //상대 위치 제어
#define C_PT_LEFT_DOWN_STEP             0x69    //상대 위치 제어
#define C_PT_RIGHT_DOWN_STEP            0x6B    //상대 위치 제어
#define C_PT_ALL_STEP                   0x71    //절대 위치 제어

#define C_PT_PAN_STEP		                0x4B	//팬 위치 제어
#define C_PT_TILT_STEP		              0x4D	//틸트 위치 제어 
#define C_PT_ZOOM_STEP                  0x4F  //줌 절대 위치 제어 
#define C_PT_FOCUS_STEP                 0x5F  //포커스 절대 위치 제어 
#define C_PT_RESET			                0x0F

#define C_PT_AUX_ON				              0x09	
#define C_PT_AUX_OFF			              0x0B
#define C_PT_ZONE                       0x23    //zone 기능
#define C_PT_DIRECT_SPEED				        0x73	  //프리셋 속도 설정
#define C_PT_LASER_STEP                 0x83    //투광기 빔폭 조절
#define C_PT_HEATER_FAN_SET             0x87    //히터, 팬 동작 온도 설정

#define Q_PT_PAN_POSITION               0x51    //팬 위치 확인
#define Q_PT_TILT_POSITION              0x53    //틸트 위치 확인
#define Q_PT_ZOOM_POSITION              0x55    //줌 위치 확인
#define Q_PT_FOCUS_POSITION             0x61    //포커스 위치 확인
#define Q_PT_POSITION                   0x81    //전체 위치 확인
#define Q_PT_MIN_POSITION               0x7D    //최소 위치 확인
#define Q_PT_MAX_POSITION               0x7B    //최대 위치 확인

#define R_PT_PAN_POSITION		            0x59	//팬 위치 응답
#define R_PT_TILT_POSITION	            0x5B	//틸트 위치 응답
#define R_ZOOM_POSITION		              0x5D
#define R_FOCUS_POSITION		            0x63


//중복되는 프로토콜을 제거 하기 위해서 사용함(아래 define에서 선택)
//#define SW_TYPE
#define PROBEDIGITAL        //프로브 디지털 카메라 사용

#ifdef SW_TYPE
#define Q_PT_HOUSIONG_STATE     0x91    //하우징 상태 확인
#define C_PT_WIPER_SET          0x93    //와이퍼 설정
#define Q_PT_VERSION            0x97    //PT 버전 확인
#endif  //SW_TYPE

#ifdef PROBEDIGITAL
//프로브 디지털 기능 추가 
#define PROB_C_PT_ALL_STEP      0x91    //절대 위치 제어 
#define PROB_Q_PT_POSITION      0x93    //위치 확인 요청
#define PROB_R_PT_POSITION      0x9B    //위치 확인 응답
#define PROB_C_PAN_DIRECTION    0xA9    //팬 방향 전환
#define PROB_C_PT_RESET         0xAB    //PT 리셋 및 공장 초기화
#define PROB_Q_PT_VERSION       0xA3    //버전 확인
#define PROB_CA_IR_LED_SET      0xA1    //IR LED SET
#define PROB_CA_ZOOM_POSITION   0x99    //현재 줌 위치 수신 및 ACK

//신우에서 중복된 기능을 사용해야 하는데 프로브 디지털에서 이미 사용하고 있어 이 커맨드를 변경함 
#define SW_Q_PT_HOUSIONG_STATE   0xB1   //하우징 상태 확인
#define SW_C_PT_WIPER_SET        0xB3   //와이퍼 설정
#define SW_Q_PT_VERSION          0xB7   //PT 버전 확인

    
void VMS_COM_IAP_MCU_RESET(void);
void PROBED_COM_LedSet_ACK(void);       				//Led 셋팅 응답
void PROBED_COM_ZoomPosition_ACK(void); 				//줌 위치가 자동 받기

#endif  //PROBEDIGITAL

#define C_IAP_SET                       0xC1    //IAP 모드 진입


//*************사용 하고 있는 AUX 번호 *********************
#define COM_AUX_WIPER			1
#define COM_AUX_DEFROST		2
#define COM_AUX_LASER			3
#define COM_AUX_CAMERA		4
#define COM_AUX_THCAMERA	5
#define COM_AUX_FAN				6
#define COM_AUX_HEATER		7
#define COM_AUX_HUB				8

//**************preset을 save 사용한 기능 번호 ********************
#define COM_PRESET_FUN_HOME_SAVE                   91
#define COM_PRESET_FUN_PAN_DIR_SAVE                92
#define COM_PRESET_FUN_TILT_DIR_SAVE               93
#define COM_PRESET_FUN_FACTORY_RST_SAVE            99
#define COM_PRESET_FUN_PT_RESET_SAVE               100
#define COM_PRESET_FUN_LENS_ACK_SAVE               131
#define COM_PRESET_FUN_LENS_NO_ACK_SAVE            132
#define COM_PRESET_FUN_ZOOM_DIR_SAVE               133
#define COM_PRESET_FUN_FOCUS_DIR_SAVE              134
#define COM_PRESET_FUN_PAN_LIMIT_START_SAVE        140
#define COM_PRESET_FUN_PAN_LIMIT_END_SAVE          176
#define COM_PRESET_FUN_TILT_UP_LIMIT_START_SAVE    180
#define COM_PRESET_FUN_TILT_UP_LIMIT_END_SAVE      189
#define COM_PRESET_FUN_TILT_DOWN_LIMIT_START_SAVE  190
#define COM_PRESET_FUN_TILT_DOWN_LIMIT_END_SAVE    199

//**************preset을 go 사용한 기능 번호 ********************
#define COM_PRESET_FUN_ZONE_START_GO             81
#define COM_PRESET_FUN_ZONE_END_GO               88
#define COM_PRESET_FUN_AUX1_ON_GO                101
#define COM_PRESET_FUN_AUX2_ON_GO                102
#define COM_PRESET_FUN_AUX3_ON_GO                103
#define COM_PRESET_FUN_AUX4_ON_GO                104
#define COM_PRESET_FUN_AUX5_ON_GO                105
#define COM_PRESET_FUN_AUX6_ON_GO                106
#define COM_PRESET_FUN_AUX7_ON_GO                107

#define COM_PRESET_FUN_AUX1_OFF_GO               111
#define COM_PRESET_FUN_AUX2_OFF_GO               112
#define COM_PRESET_FUN_AUX3_OFF_GO               113
#define COM_PRESET_FUN_AUX4_OFF_GO               114
#define COM_PRESET_FUN_AUX5_OFF_GO               115
#define COM_PRESET_FUN_AUX6_OFF_GO               116
#define COM_PRESET_FUN_AUX7_OFF_GO               117
#define COM_PRESET_FUN_ZONE_TIME_START_GO        201
#define COM_PRESET_FUN_ZONE_TIME_END_GO          210

void VMS_COM_Split(const uint8_t *buf, uint16_t len);
bool VMS_COM_isCS(const uint8_t *buf, uint16_t len);
void VMS_COM_Parser(const uint8_t *buf, uint16_t len);
uint8_t VMS_COM_getCS(const uint8_t *buf, uint16_t len);

void VMS_COM_replyPelcoD(uint8_t mdata1, uint8_t mdata2, uint8_t mdata3, uint8_t mdata4);          //pelco-D 응답 
void VMS_COM_replyShinwoo_Pt(uint8_t mdata1, uint8_t mdata2, uint8_t mdata3, uint8_t mdata4, uint8_t mdata5, uint8_t mdata6, uint8_t mdata7, uint8_t mdata8);          //신우 프로토콜 응답 
void VMS_COM_replyShinwoo_Housing(uint8_t mdata1, uint8_t mdata2, uint8_t mdata3, uint8_t mdata4, uint8_t mdata5, uint8_t mdata6, uint8_t mdata7, uint8_t mdata8);          //신우 프로토콜 응답 ;

//기능들 실제 처리 함수들
void VMS_COM_Fun_Sw_Housiong_State(void);
void VMS_COM_Fun_Pelco_QPot(uint8_t m_pelco_Qcmd, uint16_t m_pelco_Qpot);
void VMS_COM_Fun_Sw_QPot(uint8_t m_Sw_Qcmd, uint16_t m_Sw_Qpot_tilt, uint16_t m_Sw_Qpot_pan, uint16_t m_Sw_Qpot_zoom, uint16_t m_Sw_Qpot_focus);
void VMS_COM_Fun_Pelco_Step(uint8_t m_Pelco_return, uint8_t m_Pelco_step_cmd, uint8_t m_Pelco_step_d1, uint8_t m_Pelco_step_d2);
void VMS_COM_Fun_Sw_Step(uint8_t m_Sw_return, uint8_t m_Sw_step_cmd, uint8_t m_Sw_step_d1, uint8_t m_Sw_step_d2, uint8_t m_Sw_step_d3, uint8_t m_Sw_step_d4, uint8_t m_Sw_step_d5, uint8_t m_Sw_step_d6, uint8_t m_Sw_step_d7, uint8_t m_Sw_step_d8);
void VMS_COM_Fun_Aux_On(uint8_t m_wiper_setup, uint8_t m_aux_on_num);
void VMS_COM_Fun_Aux_Off(uint8_t m_aux_off_num);
void VMS_COM_Fun_Wiper_Set(uint8_t m_wiper_dir, uint8_t m_wiper_angle);
void VMS_COM_Fun_Heater_Fan_Set(uint8_t m_fan, uint8_t m_heater);
void VMS_COM_Fun_Preset_Save(uint8_t m_presest_num);
void VMS_COM_Fun_Preset_Go(uint8_t m_presestgo_num);
void VMS_COM_retrunData_task(void);
////////////////////

void PROBED_COM_replyVer(void);
void PROBED_COM_replyVer_Complete_init(void);
void PROBED_COM_replyPosition(void);                         //현재 위치값 보내기

extern uint32_t vms_preset;

#ifdef __cplusplus
}
#endif

#endif /* __VMS_COM_H */
