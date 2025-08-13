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

//**************** ��� ********************
#define C_PT_PRESET_SAVE			          0x03
#define C_PT_PRESET_CLR			            0x05
#define C_PT_PRESET_GO			            0x07

#define C_PT_RIGHT_UP_STEP              0x65    //��� ��ġ ����
#define C_PT_LEFT_UP_STEP               0x67    //��� ��ġ ����
#define C_PT_LEFT_DOWN_STEP             0x69    //��� ��ġ ����
#define C_PT_RIGHT_DOWN_STEP            0x6B    //��� ��ġ ����
#define C_PT_ALL_STEP                   0x71    //���� ��ġ ����

#define C_PT_PAN_STEP		                0x4B	//�� ��ġ ����
#define C_PT_TILT_STEP		              0x4D	//ƿƮ ��ġ ���� 
#define C_PT_ZOOM_STEP                  0x4F  //�� ���� ��ġ ���� 
#define C_PT_FOCUS_STEP                 0x5F  //��Ŀ�� ���� ��ġ ���� 
#define C_PT_RESET			                0x0F

#define C_PT_AUX_ON				              0x09	
#define C_PT_AUX_OFF			              0x0B
#define C_PT_ZONE                       0x23    //zone ���
#define C_PT_DIRECT_SPEED				        0x73	  //������ �ӵ� ����
#define C_PT_LASER_STEP                 0x83    //������ ���� ����
#define C_PT_HEATER_FAN_SET             0x87    //����, �� ���� �µ� ����

#define Q_PT_PAN_POSITION               0x51    //�� ��ġ Ȯ��
#define Q_PT_TILT_POSITION              0x53    //ƿƮ ��ġ Ȯ��
#define Q_PT_ZOOM_POSITION              0x55    //�� ��ġ Ȯ��
#define Q_PT_FOCUS_POSITION             0x61    //��Ŀ�� ��ġ Ȯ��
#define Q_PT_POSITION                   0x81    //��ü ��ġ Ȯ��
#define Q_PT_MIN_POSITION               0x7D    //�ּ� ��ġ Ȯ��
#define Q_PT_MAX_POSITION               0x7B    //�ִ� ��ġ Ȯ��

#define R_PT_PAN_POSITION		            0x59	//�� ��ġ ����
#define R_PT_TILT_POSITION	            0x5B	//ƿƮ ��ġ ����
#define R_ZOOM_POSITION		              0x5D
#define R_FOCUS_POSITION		            0x63


//�ߺ��Ǵ� ���������� ���� �ϱ� ���ؼ� �����(�Ʒ� define���� ����)
//#define SW_TYPE
#define PROBEDIGITAL        //���κ� ������ ī�޶� ���

#ifdef SW_TYPE
#define Q_PT_HOUSIONG_STATE     0x91    //�Ͽ�¡ ���� Ȯ��
#define C_PT_WIPER_SET          0x93    //������ ����
#define Q_PT_VERSION            0x97    //PT ���� Ȯ��
#endif  //SW_TYPE

#ifdef PROBEDIGITAL
//���κ� ������ ��� �߰� 
#define PROB_C_PT_ALL_STEP      0x91    //���� ��ġ ���� 
#define PROB_Q_PT_POSITION      0x93    //��ġ Ȯ�� ��û
#define PROB_R_PT_POSITION      0x9B    //��ġ Ȯ�� ����
#define PROB_C_PAN_DIRECTION    0xA9    //�� ���� ��ȯ
#define PROB_C_PT_RESET         0xAB    //PT ���� �� ���� �ʱ�ȭ
#define PROB_Q_PT_VERSION       0xA3    //���� Ȯ��
#define PROB_CA_IR_LED_SET      0xA1    //IR LED SET
#define PROB_CA_ZOOM_POSITION   0x99    //���� �� ��ġ ���� �� ACK

//�ſ쿡�� �ߺ��� ����� ����ؾ� �ϴµ� ���κ� �����п��� �̹� ����ϰ� �־� �� Ŀ�ǵ带 ������ 
#define SW_Q_PT_HOUSIONG_STATE   0xB1   //�Ͽ�¡ ���� Ȯ��
#define SW_C_PT_WIPER_SET        0xB3   //������ ����
#define SW_Q_PT_VERSION          0xB7   //PT ���� Ȯ��

    
void VMS_COM_IAP_MCU_RESET(void);
void PROBED_COM_LedSet_ACK(void);       				//Led ���� ����
void PROBED_COM_ZoomPosition_ACK(void); 				//�� ��ġ�� �ڵ� �ޱ�

#endif  //PROBEDIGITAL

#define C_IAP_SET                       0xC1    //IAP ��� ����


//*************��� �ϰ� �ִ� AUX ��ȣ *********************
#define COM_AUX_WIPER			1
#define COM_AUX_DEFROST		2
#define COM_AUX_LASER			3
#define COM_AUX_CAMERA		4
#define COM_AUX_THCAMERA	5
#define COM_AUX_FAN				6
#define COM_AUX_HEATER		7
#define COM_AUX_HUB				8

//**************preset�� save ����� ��� ��ȣ ********************
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

//**************preset�� go ����� ��� ��ȣ ********************
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

void VMS_COM_replyPelcoD(uint8_t mdata1, uint8_t mdata2, uint8_t mdata3, uint8_t mdata4);          //pelco-D ���� 
void VMS_COM_replyShinwoo_Pt(uint8_t mdata1, uint8_t mdata2, uint8_t mdata3, uint8_t mdata4, uint8_t mdata5, uint8_t mdata6, uint8_t mdata7, uint8_t mdata8);          //�ſ� �������� ���� 
void VMS_COM_replyShinwoo_Housing(uint8_t mdata1, uint8_t mdata2, uint8_t mdata3, uint8_t mdata4, uint8_t mdata5, uint8_t mdata6, uint8_t mdata7, uint8_t mdata8);          //�ſ� �������� ���� ;

//��ɵ� ���� ó�� �Լ���
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
void PROBED_COM_replyPosition(void);                         //���� ��ġ�� ������

extern uint32_t vms_preset;

#ifdef __cplusplus
}
#endif

#endif /* __VMS_COM_H */
