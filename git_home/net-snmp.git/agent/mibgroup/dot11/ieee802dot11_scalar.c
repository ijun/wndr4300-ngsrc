/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf,v 1.5 2002/07/18 14:18:52 dts12 Exp $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "ieee802dot11_scalar.h"


#define GET_BYTE(a,i) (unsigned char)( ((a)>>(8*((i)-1))) & 0XFF )
#define DISCOVERY_TOOL_PORT	8000

/** Initializes the ieee802dot11_scalar module */
static char firmwareVersion[50];
static char serialNumber[100];

void
init_ieee802dot11_scalar(void)
{
//    static oid      resetToDefault_oid[] = {1,3,6,1,4,1,546,14,1,0};
//    static oid      firmwareVersion_oid[]= {1,3,6,1,4,1,546,14,2,0};
//    static oid      serialNumber_oid[]= {1,3,6,1,4,1,546,14,3,0};
//    static oid      connectionTest_oid[]= {1,3,6,1,4,1,546,14,4,0};
    static oid      dot11ResourceTypeIDName_oid[] =
        { 1, 2, 840, 10036, 3, 1, 1, 0 };
    
    DEBUGMSGTL(("ieee802dot11_scalar", "Initializing\n"));
/*
        FILE *fp;
	int c,i;
        fp=fopen("/firmware.version","r");
        if(fp)
        {
                fscanf(fp,"%s",firmwareVersion);
                fclose(fp);
        }
        else
                strcpy(firmwareVersion,"unknow");

	system("/usr/bin/get_serial_number >/tmp/data");
	fp=fopen("/tmp/data","r");
	if(fp)
	{
		i=0;
		while((c=fgetc(fp))>=0)
			serialNumber[i++]=c;
		fclose(fp);
	}

    netsnmp_register_instance(netsnmp_create_handler_registration
                                        ("extensionGroupResetToDefault", do_resetToDefault,
                                         resetToDefault_oid,
                                         OID_LENGTH(resetToDefault_oid),
                                         HANDLER_CAN_RWRITE));

    netsnmp_register_read_only_instance(netsnmp_create_handler_registration
                                         ("extensionGroupfirmwareVersion",
                                          get_firmwareVersion,
                                          firmwareVersion_oid,
                                          OID_LENGTH(firmwareVersion_oid),
                                          HANDLER_CAN_RONLY));
    netsnmp_register_read_only_instance(netsnmp_create_handler_registration
                                         ("extensionGroupserialNumber",
                                          get_serialNumber,
                                          serialNumber_oid,
                                          OID_LENGTH(serialNumber_oid),
                                          HANDLER_CAN_RONLY));
    netsnmp_register_instance(netsnmp_create_handler_registration
                                        ("extensionGroupconnectionTest", do_connectionTest,
                                         connectionTest_oid,
                                         OID_LENGTH(connectionTest_oid),
                                         HANDLER_CAN_RWRITE));

*/
    netsnmp_register_read_only_instance(netsnmp_create_handler_registration
                                         ("dot11ResourceTypeIDName",
                                          get_dot11ResourceTypeIDName,
                                          dot11ResourceTypeIDName_oid,
                                          OID_LENGTH(dot11ResourceTypeIDName_oid),
                                          HANDLER_CAN_RONLY));

}
/*
 int
do_resetToDefault(netsnmp_mib_handler *handler,
                                        netsnmp_handler_registration
                                        *reginfo,
                                        netsnmp_agent_request_info
                                        *reqinfo,
                                        netsnmp_request_info *requests) 
{
	netsnmp_variable_list *var;
	var=requests->requestvb;
	char *info="use to reset to default(snmpset with type=integer value=1";
	switch (reqinfo->mode) {
	case MODE_GET:
		snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                	(u_char *)info,strlen(info));
        	break;
    	case MODE_SET_RESERVE1:
		if (var->type!=ASN_INTEGER) 
        		netsnmp_set_request_error(reqinfo, requests,SNMP_ERR_WRONGTYPE);
		else if(var->val_len!=sizeof(int))
			netsnmp_set_request_error(reqinfo, requests,SNMP_ERR_WRONGLENGTH);
		else if(*var->val.integer!=1)
			netsnmp_set_request_error(reqinfo, requests,SNMP_ERR_WRONGVALUE);
		else
			;
        	break;

	case MODE_SET_RESERVE2:

        	break;

    	case MODE_SET_FREE:

        	break;

    	case MODE_SET_ACTION:
		system("/bin/clear-config");
		system("/sbin/reboot");
        	break;

    	case MODE_SET_COMMIT:
        	break;

    	case MODE_SET_UNDO:
        	break;
    	default:
		MYMARK("unknow mode");
        return SNMP_ERR_GENERR;
    	}

    	return SNMP_ERR_NOERROR;
}






int
get_firmwareVersion(netsnmp_mib_handler *handler,
                            netsnmp_handler_registration *reginfo,
                            netsnmp_agent_request_info *reqinfo,
                            netsnmp_request_info *requests)
{
	switch (reqinfo->mode) {
    	case MODE_GET:
        	snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                 (u_char *)firmwareVersion,strlen(firmwareVersion));
        	break;
    	default:
                MYMARK("unknow mode");
        return SNMP_ERR_GENERR;
   	}
    	return SNMP_ERR_NOERROR;

}

int
get_serialNumber(netsnmp_mib_handler *handler,
                            netsnmp_handler_registration *reginfo,
                            netsnmp_agent_request_info *reqinfo,
                            netsnmp_request_info *requests)
{
	switch (reqinfo->mode) {
    	case MODE_GET:
        	snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                 (u_char *)serialNumber,strlen(serialNumber));
        	break;
    	default:
                MYMARK("unknow mode");
        return SNMP_ERR_GENERR;
   	}
    	return SNMP_ERR_NOERROR;

}


int
 do_connectionTest(netsnmp_mib_handler *handler,
                                        netsnmp_handler_registration
                                        *reginfou,
                                        netsnmp_agent_request_info
                                        *reqinfo,
                                        netsnmp_request_info *requests) 
{
	netsnmp_variable_list *var;
	int size,count;
	long testIP;
	long srcIP;
	FILE* fp;
	char command[100];
	char buf[100];
	int n;
	struct sockaddr_in tell_discover;
	int sockfd;
	char *info="use to connection test (snmpset with type=string size=16 ";
	var=requests->requestvb;
	switch (reqinfo->mode) {
	case MODE_GET:
		snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                	(u_char *)info,strlen(info));
        	break;
    	case MODE_SET_RESERVE1:
		if (var->type!=ASN_OCTET_STR) 
        		netsnmp_set_request_error(reqinfo, requests,SNMP_ERR_WRONGTYPE);
		else if(var->val_len!=16)
			netsnmp_set_request_error(reqinfo, requests,SNMP_ERR_WRONGLENGTH);
		else
			;
        	break;

	case MODE_SET_RESERVE2:

        	break;

    	case MODE_SET_FREE:

        	break;

    	case MODE_SET_ACTION:
		memcpy(&testIP,var->val.string,4);
		memcpy(&srcIP,var->val.string+4,4);
		memcpy(&count,var->val.string+8,4);
		memcpy(&size,var->val.string+12,4);
		sprintf(command,"ping -c %d -s %d -q %d.%d.%d.%d >/tmp/rst_ping",
			count,size,GET_BYTE(testIP,1), GET_BYTE(testIP,2), GET_BYTE(testIP,3), GET_BYTE(testIP,4));
		system(command);
		fp=fopen("/tmp/rst_ping","r");
		if(fp)
		{
			while(fgetc(fp)!='\n');
			while(fgetc(fp)!='\n');
			while(fgetc(fp)!='\n');
			fscanf(fp,"%*s %*s %*s %d",&n);
			fclose(fp);
			sprintf(buf,"%d packets received",n);
		}
		else
			strcpy(buf,"ping failed");
		sockfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (sockfd == -1) 
			break;
		memset(&tell_discover,0,sizeof(struct sockaddr_in));
		tell_discover.sin_family=AF_INET;
		tell_discover.sin_port=htons(DISCOVERY_TOOL_PORT);
		tell_discover.sin_addr.s_addr=srcIP;
		n=sendto(sockfd,buf,strlen(buf),0,(struct sockaddr*)&tell_discover,sizeof(struct sockaddr));
		if(n == -1)
			printf("send message fail\n");
		close(sockfd);
		break;

    	case MODE_SET_COMMIT:
        	break;

    	case MODE_SET_UNDO:
        	break;
    	default:
		MYMARK("unknow mode");
       		 return SNMP_ERR_GENERR;
    	}

    	return SNMP_ERR_NOERROR;
}
*/
int
get_dot11ResourceTypeIDName(netsnmp_mib_handler *handler,
                            netsnmp_handler_registration *reginfo,
                            netsnmp_agent_request_info *reqinfo,
                            netsnmp_request_info *requests)
{
	char* dot11ResourceTypeIDName="RTID";
    switch (reqinfo->mode) {

    case MODE_GET:
        snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                 (u_char *)dot11ResourceTypeIDName,4);
        break;
    default:
         	MYMARK("unknow mode");
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
