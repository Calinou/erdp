#include "rdp_connect.h"

void rdp_connect(GtkButton *connect, gpointer erdp) {
	/*get the string info*/
	GtkEntry *rip = (GtkEntry *) find_child(erdp, "address");
	GtkEntry *ruser = (GtkEntry *) find_child(erdp, "user");
	GtkEntry *rpass = (GtkEntry *) find_child(erdp, "pass");

	/*format my strings correctly*/
	char *fip = malloc(strlen("/v:")+strlen(gtk_entry_get_text(rip))+1);
	fip = g_strconcat("/v:", gtk_entry_get_text(rip), NULL);
	char *fuser = malloc(strlen("/u:")+strlen(gtk_entry_get_text(ruser))+1);
	fuser = g_strconcat("/u:", gtk_entry_get_text(ruser), NULL);
	char *fpass = malloc(strlen("/p:")+strlen(gtk_entry_get_text(rpass))+1);
	fpass = g_strconcat("/p:", gtk_entry_get_text(rpass), NULL);

	/*and call xfreerdp*/
	g_printf("Calling xfreerdp with arguments: %s %s %s\n", fip, fuser, fpass);
	execl("/usr/bin/xfreerdp", "/cert-ignore", fip, fuser, fpass, NULL);
	/*code never gets here*/
	return;
}

void cancel() {
	gtk_main_quit();
	return;
}
