#ifndef EM9636_H
#define EM9636_H

#define EM9636_USB_MAX_COUNT                        16 //����֧��USBģ�����
#define EM9636_BASE_FREQ                            16000000.0//����ʱ�ӣ�16M
#define EM9636_MAXADCHCNT                           32 //AD���ͨ����
#define EM9636_MAXIOCHCNT                           32 //IO���ͨ����
#define EM9636_MAXCTCHCNT                           6 //���������ͨ����
#define EM9636_MAXECCHCNT                           2 //���������ͨ����
#define EM9636_MAXPWMCHCNT                          3 //���������ͨ����

//������ʽ
#define EM9636_STARTMODE_ICLK                       0 //��ʱ�������ɼ�
#define EM9636_STARTMODE_ECLK                       1 //��ʱ�������ɼ�

//αͬ������
#define EM9636_PSYNC_NO								0 //αͬ����Ч
#define EM9636_PSYNC_YES							1 //αͬ����Ч

//����Դ
#define EM9636_TRI_IN								0 //�ڲ�
#define EM9636_TRI_EXTERN							1 //�ⲿ

//������ʽ
#define EM9636_TRI_UPEDGE							0 //������
#define EM9636_TRI_HIGHLEVEL						1 //�ߵ�ƽ
#define EM9636_TRI_DOWNEDGE							2 //�½�����
#define EM9636_TRI_LOWLEVEL							3 //�͵�ƽ

//AD�ɼ���Χ
#define EM9636_AD_RANGE_N10_10V                      0L //��10V
#define	EM9636_AD_RANGE_N5_5V                        1L //��5V
#define	EM9636_AD_RANGE_0_10V                        2L //0~10V
#define	EM9636_AD_RANGE_0_5V                         3L //0~5V
#define	EM9636_AD_RANGE_0_20mA                       4L //0~20mA

//AD���˻��ǲ��
#define	EM9636_AD_SINGLE                             0L //����
#define	EM9636_AD_DIFF                               1L //���

//AD����
#define EM9636_AD_GAIN_1                             0 //1������
#define EM9636_AD_GAIN_2                             1 //2������
#define EM9636_AD_GAIN_5                             2 //5������
#define EM9636_AD_GAIN_10                            3 //10������

//DA�ɼ���Χ
#define EM9636_DA_RANGE_N10_10V                      0L //��10V
#define	EM9636_DA_RANGE_N5_5V                        1L //��5V
#define	EM9636_DA_RANGE_0_10V                        2L //0~10V
#define	EM9636_DA_RANGE_0_5V                         3L //0~5V

//DA�����ʽ
#define EM9636_DA_MODE_CODE                          0L //ԭ��ֵ���
#define	EM9636_DA_MODE_VALUE                         1L //��ѹֵ�����mV��

//������ʽ
#define EM9636_CT_MODE_COUNT                         0 //����
#define EM9636_CT_MODE_HFREQ                         1 //���Ƶ
#define EM9636_CT_MODE_LFREQ                         3 //���Ƶ

//IO����
#define EM9636_IO_IN                                 0 //����
#define EM9636_IO_OUT                                1 //���

//IO�Ƿ��FIFO
#define EM9636_IOINFIFO_NO                           0 //����FIFO
#define EM9636_IOINFIFO_YES                          1 //��FIFO

#define EM9636_TIMOUT_MS                             1000 //��ʱ������

extern "C"
{

I32 _stdcall EM9636_DeviceCreate();
//�������ܣ������豸
//��ڲ�����
//      ��
//����ֵ��-1�������豸ʧ��
//        ����ֵΪ�豸��������Ժ���豸��ز����о�Ҫʹ���䷵��ֵ

void _stdcall EM9636_DeviceClose( I32 hDevice );
//�������ܣ��ر��豸��ͬʱ�ͷ��豸��ռ����Դ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//����ֵ����

I32 _stdcall EM9636_CmdConnect( I32 hDevice, char* strIP, I32 ipBC, I32 cmdPort, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ���������˿�
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//             strIP���豸IP
//              ipBC��strIP�ĳ��ȣ��˲���Ϊ0ʱ��ʾstrIP����0Ϊ�������ַ�����
//           cmdPort������˿ںš�
//         timeOutMS����ʱ��������
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_DataConnect( I32 hDevice, I32 dataPort, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ��������ݶ˿ڣ����ô˺���֮ǰ�����ȵ���EM9636_CmdConnect
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//          dataPort�����ݶ˿ںš�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

void _stdcall EM9636_CmdClose( I32 hDevice, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ��ر�����˿�
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

void _stdcall EM9636_DataClose( I32 hDevice, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ��ر����ݶ˿�
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_AdSetChRange( I32 hDevice, I32 beginNo, I32 endNo, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�����ADͨ����Χ��ֻ�����÷�Χ�ڵ�ͨ���ɼ�����
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//           beginNo����ʼͨ���ţ�1~32
//             endNo����ֹͨ����
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_AdSetEndMode( I32 hDevice, I32 endMode, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�����AD��˫�˷�ʽ��ע��Ҫ���豸����һ��
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//           endMode����˫�˷�ʽ��0��ʾ���ˣ�1��ʾ���
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_AdSetRange( I32 hDevice, I32 rangeInx, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�����AD�ɼ���Χ��ע��Ҫ���豸����һ��
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//          rangeInx���ɼ���Χ
//                    0����10V
//                    1����5V
//                    2��0~10V
//                    3��0~5V
//                    4��0~20mA
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_AdSetGain( I32 hDevice, I32 gainInx, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�����AD����
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//           gainInx������ϵ��
//                    0��û������
//                    1��2������
//                    2��5������
//                    3��10������
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_AdReadOnceCode( I32 hDevice, I32 beginChNo, I32 endChNo, U16* adCode, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ���ȡһ��AD����ֵ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//         beginChNo����ʼͨ���ţ�1~endChNo
//           endChNo����ֹͨ���ţ�beginChNo~32
//���ڲ�����
//            adCode��AD����ԭ��ֵ���飬����������Ԫ����ĿΪ��endChNo - beginChNo + 1������Ҫ�û�����ռ�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_AdGetValue( I32 hDevice, U16* adCode, I32 adCodeCount, double* adValue );
//�������ܣ���ADԭ��ֵת��������ֵ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//            adCode��ADԭ��ֵ���飬����������Ԫ����ĿΪcodeCount
//       adCodeCount��ԭ��ֵ����������Ԫ����Ŀ
//���ڲ�����
//           adValue��AD����ֵת������������СΪadCodeCount����Ҫ�û�����ռ�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_TriSetSrc( I32 hDevice, I32 triSrc, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ����ø��ٲɼ�����Դ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//            triSrc������Դ
//                    0,�ڴ���
//                    1,�ⴥ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_TriSetMode( I32 hDevice, I32 triMode, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ����ø��ٲɼ�������ʽ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//           triMode��������ʽ
//                    0,�����ش���
//                    1,�ߵ�ƽ����
//                    2,�½��ش���
//                    3,�͵�ƽ����
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_HcSetChFreq( I32 hDevice,  F64 chFreq, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�����ͨ���л�Ƶ��
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//            chFreq��ͨ���л�Ƶ�ʣ����250000(250K)
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_HcSetGroupFreq( I32 hDevice,  F64 groupFreq, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�������Ƶ��
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//         groupFreq����Ƶ�ʣ���ҪС�� ͨ���л�Ƶ��/ͨ����
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_HcStart( I32 hDevice, I32 isPSync, I32 clkSrc, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�����Ӳ�����Ʋɼ�
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//           isPSync���Ƿ�αͬ����0��αͬ����1αͬ��
//            clkSrc��ʱ��Դ��0��ʱ�ӣ�1��ʱ��
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_HcStop( I32 hDevice, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�ֹͣӲ�����Ʋɼ�
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636M_HcStart( I32 hDevice, I32 isPSync, I32 clkSrc, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�����Ӳ�����Ʋɼ�����ΪEM9636M��λ���������Ƚ�С����Ҫ��ʱ��ȡ���ݣ����ô˺�����dll�н������߳��Զ���ȡ����
//          Ȼ��洢���������С��û����Ե���EM9636M_HcSFifoRead�����ӻ������ж�ȡ����
//          �����EM9636M_HcStop���ʹ��
//          ע�⣺�˺������ú��벻Ҫ����EM9636M_HcSFifoRead
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//           isPSync���Ƿ�αͬ����0��αͬ����1αͬ��
//            clkSrc��ʱ��Դ��0��ʱ�ӣ�1��ʱ��
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636M_HcStop( I32 hDevice, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�ֹͣӲ�����Ʋɼ��������EM9636M_HcStart���ʹ��
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636M_HcSFifoCanReadCount( I32 hDevice, I32* canReadCount );
//�������ܣ��õ���λ��������������ݸ���
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//         canReadCount���ɶ����ݸ�����ÿ������ռ2���ֽڡ�
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636M_HcSFifoRead( I32 hDevice, I32 dataCount, U16* dataBuffer, I32* realReadCount );
//�������ܣ���Ӳ�����Ʋɼ�������ʹ�ô˺���������λ���������еĲɼ����
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//         dataCount�����ݸ�����ÿ������ռ2���ֽڡ�
//���ڲ�����
//        dataBuffer�����ݻ��������飬��Ҫ�û����䣬Ԫ�ظ�������ΪdataCount
//     realReadCount��ʵ�ʶ������ݸ�������Ҫ�û�����
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_HcReadData( I32 hDevice, I32 dataCount, U16* dataBuffer, I32* realReadCount, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ���Ӳ�����Ʋɼ�������ʹ�ô˺������زɼ����
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//         dataCount�����ݸ�����ÿ������ռ2���ֽڡ�
//���ڲ�����
//        dataBuffer�����ݻ��������飬��Ҫ�û����䣬Ԫ�ظ�������ΪdataCount
//     realReadCount��ʵ�ʶ������ݸ�������Ҫ�û�����
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��
I32 _stdcall EM9636M_HcFifoStatus( I32 hDevice, I32* hFifoStatus, I32* sFifoStatus, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ���Ӳ�����Ʋɼ�������ʹ�ô˺����ж���λ��
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//���ڲ�����
//       hFifoStatus����λ��Ӳ�����������
//       sFifoStatus����λ��������������
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_AdGetCode( I32 hDevice, U16* usCode, I32 codeCount, U16* adCode, I32* adCodeCount );
//�������ܣ���ADԭ���ԭ��ֵ����ȡ�����������ٻ���������IOֵ����ʱ����Ҫ���ô˺�����ȡADԭ��
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//            usCode��ԭ��ֵ���飬����������Ԫ����ĿΪcodeCount����EM9636_HcReadData����
//         codeCount��ԭ��ֵ����������Ԫ����Ŀ����Ҫ�Ǹ��ٻ�����������ͨ����Ŀ����������
//���ڲ�����
//            adCode��ADԭ��ֵ���飬�����СΪadCodeCount����Ҫ�û�����ռ�
//       adCodeCount��ADԭ��ֵ������
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_IoGetCode( I32 hDevice, U16* usCode, I32 codeCount, U16* ioCode, I32* ioCodeCount );
//�������ܣ���ADԭ���ԭ��ֵ����ȡ�����������ٻ���������IOֵ����ʱ����Ҫ���ô˺�����ȡADԭ��
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//            usCode��ԭ��ֵ���飬����������Ԫ����ĿΪcodeCount����EM9636_HcReadData����
//         codeCount��ԭ��ֵ����������Ԫ����Ŀ����Ҫ�Ǹ��ٻ�����������ͨ����Ŀ����������
//���ڲ�����
//            ioCode��ADԭ��ֵ���飬�����СΪadCodeCount����Ҫ�û�����ռ�
//       ioCodeCount��ADԭ��ֵ������
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_DaSetOutMode( I32 hDevice, I32 chNo, I32 codeOrVal, long rangeInx, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�DA�����ʽ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1~4
//         codeOrVal��0��ʾԭ��ֵ�����1��ʾ����ֵ���
//          rangeInx�������Χ
//                    0����10V
//                    1����5V
//                    2��0~10V
//                    3��0~5V
//                    4��0~20mA
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_DaSet( I32 hDevice, I32 chNo, I16 daValue, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�����DA���ֵ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1~4
//           daValue������EM9636_DaSetOutMode���ã���ʾԭ��ֵ���ߺ������ߺ���ֵ
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_DaAutoSet( I32 hDevice, I16 daValue[4], I32 stepCnt, I32 stepTime, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�����DA�Զ�������ݣ�������Ϊ���ƣ�һ���û��ò���
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//           daValue�������ĸ�Ԫ�ص����飬�ֱ��Ӧ1~4ͨ����΢��ֵ
//           stepCnt��������32~1000
//          stepTime��ÿ�������1~100ms
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_DaAutoGet( I32 hDevice, I16 daValue[4], I32* stepCnt, I32* stepTime, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ��õ���ǰDA�Զ����ֵ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//���ڲ�����
//           daValue�������ĸ�Ԫ�ص����飬�ֱ��Ӧ1~4ͨ����΢��ֵ
//           stepCnt��������32~1000
//          stepTime��ÿ�������1~100ms
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_IoSetDir( I32 hDevice, I8 dir[4], I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ����ÿ���������
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//               dir��4�ֽ����飬dir[0]��ӦIO1~IO8��dir[1]��ӦIO9~IO16
//���ڲ�����
//                  ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_IoGetAll( I32 hDevice, I8 iStatus[32], I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ��õ�����ͨ��������ֵ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//���ڲ�����
//           iStatus��32�ֽ�����
//                    iStatus[0]~iStatus[15]��ӦIO1~IO16
//                    iStatus[16]~iStatus[23]��ӦDI1~DI8
//                    iStatus[24]~iStatus[31]��ӦDO1~DO8
//
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_IoSetAll( I32 hDevice, I8 oStatus[32], I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ���������ͨ��������ֵ�������Ӧ��������������Ϊ���룬���Ӧ��������������Ч
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//           oStatus��32�ֽ�����
//                    oStatus[0]~oStatus[15]��ӦIO1~IO16
//                    oStatus[16]~oStatus[23]��ӦDI1~DI8
//                    oStatus[24]~oStatus[31]��ӦDO1~DO8
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_IoInFifo( I32 hDevice, I8 isInFifo, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ��õ�����ͨ��������ֵ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//          isInFifo��0��ʾIO1~IO16������FIFO
//                    1��ʾIO1~IO16����FIFO
//
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_EcClear( I32 hDevice, I32 chNo, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ���ָ��ͨ���ı���������
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1~2
//
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_EcReadCodeAll( I32 hDevice, I32 abCode[2], I16 zCode[2], I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ���ָ��ͨ���ı���������
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//���ڲ�����
//            abCode��������ABֵ��32λ�з������飬��Ԫ�ظ���Ϊ2����Ҫ�û�����ռ䡣
//             zCode������������ֵ��16λ�з������飬��Ԫ�ظ���Ϊ2����Ҫ�û�����ռ䡣
//
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_CtSetModeAll( I32 hDevice, U16 ctMode[EM9636_MAXCTCHCNT], I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ���������·�������Ĺ�����ʽ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//            ctMode��������������ʽ��6Ԫ����������
//                    0������
//                    1�����Ƶ
//                    3�����Ƶ
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_CtSetFreqBase( I32 hDevice, I32 chNo, F64 freqBase_ms, F64* real_ms, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�����ָ��ͨ���ļ�������Ƶ��׼�������ڣ��Ժ���Ϊ��λ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1~6
//       freqBase_ms����Ƶ��׼���ڣ��Ժ���Ϊ��λ
//���ڲ�����
//           real_ms��ʵ�ʲ�Ƶ��׼������������freqBase_msһ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_CtReadCodeAll( I32 hDevice, U32 ctCode[EM9636_MAXCTCHCNT], I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ���ȡ����·��������ԭ��ֵ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//���ڲ�����
//            ctCode��������ԭ��ֵ������Ǽ�����ʽ���Ǽ���ֵ������ǲ�Ƶ����Ҫ�������ת����Ƶ��ֵ
//                    �޷���32λ
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_CtCodeToValue( I32 hDevice, I32 chNo, U32 ctCode, F64* ctValue );
//�������ܣ���������ֵ����ԭ��ֵת���ɶ�Ӧ������ֵ��������ʽ����Ϊ����ֵ����Ƶ��ʽ����ΪƵ��ֵ���˺�����ת�������EM9636_CtSetModeAll�й�
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1~6
//            ctCode��������ԭ��ֵ����EM9636_CtReadCodeAll��������
//���ڲ�����
//           ctValue��������ʽ��Ϊ����ֵ����Ƶ��ʽ��Ϊ��Ƶֵ
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_CtClear( I32 hDevice, I32 chNo, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�ָ��ͨ������������	
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1~6
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_CmdEnableWTD( I32 hDevice, U16 overTimeS, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�ʹ��ͨѶ���Ź�,����λ����overTimeS����û�н��յ��κ��������ΪͨѶ�жϣ���ʱ��λ����Ҫ���µ���EM9636_CmdConnect������
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//         overTimeS����ʱ����
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_PwmSetPulse( I32 hDevice, I32 chNo, F64 freq, F64 duty, F64* realFreq, F64* realDuty, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�����PWMƵ�ʺ�ռ�ձȡ�
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//              chNo��ͨ����1~3
//              freq��Ƶ�ʣ���СΪ250Hz
//              duty��ռ�ձȣ�0~1
//���ڲ�����
//          realFreq��ʵ��Ƶ�ʣ�ͨ����freqһ��
//          realDuty��ʵ��ռ�ձȣ�ͨ����dutyһ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_PwmSet1Pulse32bit( I32 hDevice, I32 chNo, F64 freq, F64 duty, F64* realFreq, F64* realDuty, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ�ֻ�ö��Ƴ�1·32λPWM��Ʒ�ſ���ʹ�ã�����PWMƵ�ʺ�ռ�ձȡ�
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//              chNo��ͨ����ֻ��Ϊ1
//              freq��Ƶ�ʣ���СΪ0.01Hz
//              duty��ռ�ձȣ�0~1
//���ڲ�����
//          realFreq��ʵ��Ƶ�ʣ�ͨ����freqһ��
//          realDuty��ʵ��ռ�ձȣ�ͨ����dutyһ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_PwmStartOrStopAll( I32 hDevice, I8 startOrStop, I32 timeOutMS = EM9636_TIMOUT_MS  );
//�������ܣ�ʹ�ܻ��ֹPWM�����Ŀǰֻ��ȫ��ʹ�ܺ�ȫ����ֹ
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//       startOrStop��0��ʾ��ֹ����PWM�����1��ʾʹ������PWM���
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636M_PwmStartAll( I32 hDevice, I8 startOrStop[EM9636_MAXPWMCHCNT], I8 is90[EM9636_MAXPWMCHCNT], I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ��趨����ͨ����PWM�����ʼ����ֹͣ,������ֻ֧��EM9636M�Լ�����EM9636���Ʋ�Ʒ��
//ע�⣺��ʹ��PWM����ǰ��Ӧ�õ���EM9636_IoSetDir������IO1~IO8��������
//��ڲ�����
//                hDevice���豸�����EM9636_DeviceCreate��������ֵ
//            startOrStop�������������飬����Ԫ��0~2��ӦPWM1~PWM3����PWM1Ϊ����
//                         startOrStop[0]=0��ֹͣ���
//                         startOrStop[0]=1���������
//                   is90����λ�������飬����Ԫ��0~2��ӦPWM1~PWM3����PWM1Ϊ����
//                         is90[0]=0������ͺ�90��
//                         is90[0]=1��������ͺ�90��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636M_PwmSetCount( I32 hDevice, I32 chNo, U32 pwmCount, I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ��趨����������,�˺���ֻ�ж��Ʋ�Ʒ֧��
//��ڲ�����
//                hDevice���豸���
//                   chNo��ͨ���ţ�1~3
//               setCount����������������Ϊ�����ʾ�������
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636M_PwmIsOver( I32 hDevice, I8 isOver[EM9636_MAXPWMCHCNT], I32 timeOutMS = EM9636_TIMOUT_MS );
//�������ܣ����ƶ�������������������£��ж�PWM����Ƿ����,�˺���ֻ��EM9636M�Ͳ��ֶ���EM9636֧��
//��ڲ�����
//                hDevice���豸�����EM9636_DeviceCreate��������ֵ
//                 isOver���Ƿ���ɣ�����Ԫ��0~2��ӦPWM1~3����PWM1Ϊ����
//                           isOver[0]=0�����û�����
//                           isOver[0]=1������Ѿ����
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_ReadW( I32 hDevice, U32 regAddress, U32* regData, I32 timeOutMS = EM9636_TIMOUT_MS  );
//�������ܣ���ȡ��λ���Ĵ���������������ʹ�ã���ͨ�û��������
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//        regAddress���Ĵ�����ַ
//           regData���Ĵ������ݣ���ʮ��λ��Ч
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_WriteW( I32 hDevice, U32 regAddress, U32 regData, I32 timeOutMS = EM9636_TIMOUT_MS  );
//�������ܣ���ȡ��λ���Ĵ���������������ʹ�ã���ͨ�û��������
//��ڲ�����
//           hDevice���豸�����EM9636_DeviceCreate��������ֵ
//        regAddress���Ĵ�����ַ
//           regData���Ĵ������ݣ���ʮ��λ��Ч
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9636_OlFileOpen( I8* filePathName );
//�������ܣ��������ļ�
//��ڲ�����
//      filePathName���ļ�·��
//����ֵ��-1,���ļ�ʧ��
//        ����ֵΪ�ļ����

I32 _stdcall EM9636_OlGetDataBytesCount( I32 fileHandle );
//�������ܣ������������ļ��еõ��������������ֽ�λ��λ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//����ֵ��>0,��������
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9636_OlGetAdEnCh( I32 fileHandle, I8 enCh[EM9636_MAXADCHCNT] );
//�������ܣ������������ļ��еõ�ʹ��ͨ�������˲����������ٲɼ�
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//            enCh������AD��ʹ��ͨ��������Ϊ32���ֽ�����
//����ֵ��>0,����ʹ��ͨ������
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9636_OlGetAdChRange( I32 fileHandle, I32* beginChNo, I32* endChNo );
//�������ܣ������������ļ��еõ�ADͨ����Χ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//       beginChNo����ʼͨ��
//         endChNo��ֹͣͨ��
//����ֵ��>0,����ʹ��ͨ������
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9636_OlGetGroupBytesCount( I32 fileHandle );
//�������ܣ������������ļ��еõ���������ÿ���ֽ�����Ҳ����ÿ�β�������õ������ֽ���
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//����ֵ��>0,ÿ���ֽ���
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9636_OlGetGroupFreq( I32 fileHandle, F64* groupFreq );
//�������ܣ������������ļ��еõ���Ƶ��ֵ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//       groupFreq����HzΪ��λ�Ĳɼ�Ƶ��
//����ֵ��=0,��ʾ�ɹ�

I32 _stdcall EM9636_OlGetOriginalCode( I32 fileHandle, I32 readPos, U32 bytesCount, U8* originalCode, U32* realBC );
//�������ܣ������������ļ��л�ȡԭʼ����
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//         readPos����ȡλ�ã���һ���ɼ�ͨ����һ���ɼ���Ķ�ȡλ��Ϊ0�����Ϊ-1��ʾ�ӵ�ǰλ�ö�ȡ
//      bytesCount��Ҫ��ȡ���ֽ�����
//���ڲ�����
//    originalCode�����ݻ���������Ҫ�û����䣬���СΪbytesCount
//          realBC��ʵ�ʶ�ȡ���ֽ���
//����ֵ��>0,�����ļ���ǰָ���λ�ã���������ȷ����һ�ζ�ȡ��λ��
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9636_OlDirOpen( I8* path );
//�������ܣ��������ļ�Ŀ¼���˺��������ϸ�ʽ��Ŀ¼�򿪣�׼�����մ洢����˳������ļ�
//��ڲ�����
//            path��Ŀ¼��·������Ŀ¼�ڲ��ṹ����������ļ��洢�̵Ľṹһ�¡�
//                  �����ļ��洢��Ŀ¼�ṹ����Ŀ¼�������ļ��У�ÿ�������ļ������������ļ���
//����ֵ��-1,���ļ�ʧ��
//        ����ֵΪ�ļ����

I32 _stdcall EM9636_OlGetAdChCode( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, U16* adChCode, U32* adCodeCount );
//�������ܣ��Ӹ��ٲɼ�ԭʼ�����л�ȡADԭ��ֵ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ָ�����ļ�ʹ��ͨ������ţ�����ʹ����AD5��AD6����ͨ������chInx=0ʱ��ʾҪȡ��AD5��ֵ��chInx=1ʱ��ʾҪȡ��AD6��ֵ
//      bytesCount��originalCode���������ݵ��ֽ�����
//    originalCode��ԭʼ�뻺����
//���ڲ�����
//        adChCode��ָ��ͨ�������ݽ������飬��Ҫ�û�����ռ䣬����Ϊ16λ�޷������ͣ������СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9636_OlGetGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���adCodeCount����ȡ���顣
//     adCodeCount��adChCode���ص���Ч���ݸ�����=0���ʾ�����ء�
//����ֵ��<0,��ʾ����ʧ��

I32 _stdcall EM9636_OlAdGetValue( I32 fileHandle, U16* usCode, I32 codeCount, double* adValue );
//�������ܣ�������AD����ת��������ֵ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//          usCode��ԭ��ֵ��������Ӧ����EM9636_OlGetAdChCode���ص�ֵ
//       codeCount��AD���ݸ�����Ӧ����EM9636_OlGetAdChCode�е�adCodeCount����ֵ
//���ڲ�����
//         adValue������ֵ�����������С����С��codeCount
//����ֵ��<0,��ʾ����ʧ��

I32 _stdcall EM9636_OlAdGetRange( I32 fileHandle, I8* rangeInx );
//�������ܣ������������ļ��еõ��ɼ���Χ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//       rangeInx���ɼ���Χ����
//����ֵ��=0,��ʾ�ɹ�

I32 _stdcall EM9636_OlGetChFreq( I32 fileHandle, F64* chFreq );
//�������ܣ������������ļ��еõ�ͨ���л�Ƶ��ֵ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//       chFreq����HzΪ��λ�Ĳɼ�Ƶ��
//����ֵ��=0,��ʾ�ɹ�

I32 _stdcall EM9636_OlGetIsPSync( I32 fileHandle, I32* isPSync );
//�������ܣ������������ļ��еõ��Ƿ�Ϊαͬ���ɼ�
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//         isPSync������0��ʾ����αͬ����1Ϊαͬ��
//����ֵ��=0,��ʾ�ɹ�

I32 _stdcall EM9636_OlGetCtEnCh( I32 fileHandle, I8* enCh );
//�������ܣ������������ļ��еõ���������ʹ��ͨ�����˲����������ٲɼ�
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//            enCh��6Ԫ�����飬����1��ʾ��ͨ���洢
//����ֵ��>=0,��ʾ�ɹ�

I32 _stdcall EM9636_OlGetCtMode( I32 fileHandle, I8* ctMode );
//�������ܣ������������ļ��еõ��������Ĺ�����ʽ���˲����������ٲɼ�
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//          ctMode��6Ԫ������
//����ֵ��>=0,��ʾ�ɹ�

I32 _stdcall EM9636_OlGetCtGate( I32 fileHandle, I32* ctGate );
//�������ܣ������������ļ��еõ��������Ĺ�����ʽ���˲����������ٲɼ�
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//          ctGate��6Ԫ������
//����ֵ��>=0,��ʾ�ɹ�

I32 _stdcall EM9636_OlGetEcEnCh( I32 fileHandle, I8* enCh );
//�������ܣ������������ļ��еõ���������ʹ��ͨ�����˲����������ٲɼ�
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//            enCh��2Ԫ�����飬����1��ʾ��ͨ���洢
//����ֵ��>=0,��ʾ�ɹ�
I32 _stdcall EM9636_OlGetIoEnCh( I32 fileHandle, I8* enCh );
//�������ܣ������������ļ��еõ��Ŀ�����ʹ���飬�˲����������ٲɼ�
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//            enCh��4Ԫ�����飬����1��ʾ����IO�洢
//����ֵ��>=0,��ʾ�ɹ�

I32 _stdcall EM9636_OlGetIoInFifo( I32 fileHandle, I8* ioInFifo );
//�������ܣ������������ļ��еõ��Ŀ������Ƿ��FIFO��Ϣ���˲������ڸ��ٲɼ�
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//���ڲ�����
//        ioInFifo���ֽ�ָ�룬����1��ʾIO1��IO16����FIFO��ע��ֻ����StartMode��Ϊ0��ʱ�����Ч��
//����ֵ��>=0,��ʾ�ɹ�

I32 _stdcall EM9636_OlGetIoInFifoCode( I32 fileHandle, U32 bytesCount, U8* originalCode, U16* ioCode, U32* ioCodeCount );
//�������ܣ��Ӹ��ٲɼ�ԭʼ�����л�ȡIO1~IO16ֵ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//      bytesCount��originalCode���������ݵ��ֽ�����
//    originalCode��ԭʼ�뻺����
//���ڲ�����
//          ioCode��ָ��ͨ�������ݽ������飬��Ҫ�û�����ռ䣬����Ϊ16λ�޷������ͣ������СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9636_OlGetGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���adCodeCount����ȡ���顣
//     ioCodeCount��ioCode���ص���Ч���ݸ�����=0���ʾ�����ء�
//����ֵ��<0,��ʾ����ʧ��

I32 _stdcall EM9636_OlGetLsGroupBytesCount( I32 fileHandle );
//�������ܣ������������ļ��еõ���������ÿ���ֽ�����Ҳ����ÿ�β�������õ������ֽ���
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//����ֵ��>0,ÿ���ֽ���
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9636_OlGetLsAdChCode( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, U16* adCode, U32* adCodeCount );
//�������ܣ������ٲɼ�ԭʼ�����л�ȡADԭ��ֵ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ָ�����ļ�ʹ��ͨ������ţ�����ʹ����AD5��AD6����ͨ������chInx=0ʱ��ʾҪȡ��AD5��ֵ��chInx=1ʱ��ʾҪȡ��AD6��ֵ
//      bytesCount��originalCode���������ݵ��ֽ�����
//    originalCode��ԭʼ�뻺����
//���ڲ�����
//        adChCode��ָ��ͨ�������ݽ������飬��Ҫ�û�����ռ䣬����Ϊ16λ�޷������ͣ������СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9636_OlGetLsGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���adCodeCount����ȡ���顣
//     adCodeCount��adChCode���ص���Ч���ݸ�����=0���ʾ�����ء�
//����ֵ��<0,��ʾ����ʧ��

I32 _stdcall EM9636_OlGetLsIoGroupCode( I32 fileHandle, I32 groupInx, U32 bytesCount, U8* originalCode, U8* ioCode, U32* ioCodeCount );
//�������ܣ������ٲɼ�ԭʼ�����л�ȡIOԭ��ֵ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//        groupInx����������ÿ8��IOͨ��Ϊһ�顣
//      bytesCount��originalCode���������ݵ��ֽ�����
//    originalCode��ԭʼ�뻺����
//���ڲ�����
//          ioCode��ָ��������ݽ������飬��Ҫ�û�����ռ䣬����Ϊ8λ�޷������ͣ������СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9636_OlGetLsGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���ioCodeCount����ȡ���顣
//     ioCodeCount��adChCode���ص���Ч���ݸ�����=0���ʾ�����ء�
//����ֵ��<0,��ʾ����ʧ��

I32 _stdcall EM9636_OlGetLsCtChCode( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, U32* ctCode, U32* ctCodeCount );
//�������ܣ������ٲɼ�ԭʼ�����л�ȡCTԭ��ֵ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ָ�����ļ�ʹ��ͨ������ţ�����ʹ����CT5��CT6����ͨ������chInx=0ʱ��ʾҪȡ��CT5��ֵ��chInx=1ʱ��ʾҪȡ��CT6��ֵ
//      bytesCount��originalCode���������ݵ��ֽ�����
//    originalCode��ԭʼ�뻺����
//���ڲ�����
//          ctCode��ָ��ͨ�������ݽ������飬��Ҫ�û�����ռ䣬����Ϊ32λ�޷������ͣ������СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9636_OlGetLsGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���ctCodeCount����ȡ���顣
//     ctCodeCount��adChCode���ص���Ч���ݸ�����=0���ʾ�����ء�
//����ֵ��<0,��ʾ����ʧ��

I32 _stdcall EM9636_OlGetLsEcChCode( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, I32* abCode, I32* zCode, U32* ecCodeCount );
//�������ܣ������ٲɼ�ԭʼ�����л�ȡ������ԭ��ֵ
//��ڲ�����
//      fileHandle���ļ������EM9636_OlFileOpen�ķ���ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ָ�����ļ�ʹ��ͨ������ţ�����ʹ����EC2һ��ͨ������chInx=0ʱ��ʾҪȡ��EC2��ֵ
//      bytesCount��originalCode���������ݵ��ֽ�����
//    originalCode��ԭʼ�뻺����
//���ڲ�����
//          abCode��ָ��ͨ����AB���ݽ������飬��Ҫ�û�����ռ䣬����Ϊ32λ�з������ͣ������СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9636_OlGetLsGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���ecCodeCount����ȡ���顣
//           zCode��ָ��ͨ����Z���ݽ������飬��Ҫ�û�����ռ䣬����Ϊ32λ�з������ͣ������СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9636_OlGetLsGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���ecCodeCount����ȡ���顣
//     ecCodeCount��adChCode���ص���Ч���ݸ�����=0���ʾ�����ء�
//����ֵ��<0,��ʾ����ʧ��

};

#endif