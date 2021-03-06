#include <unistd.h>

#include "backpack.h"

CAMLprim value
caml_backpack_sync(value val_unit)
{
	CAMLparam1(val_unit);

	caml_enter_blocking_section();
	sync();
	caml_leave_blocking_section();

	CAMLreturn(Val_unit);
}

CAMLprim value
caml_backpack_fsync(value val_fd)
{
	CAMLparam1(val_fd);
	int r;

	caml_enter_blocking_section();
	r = fsync(Int_val(val_fd));
	caml_leave_blocking_section();

	if (r == -1)
		uerror("fsync", Nothing);

	CAMLreturn(Val_unit);
}

CAMLprim value
caml_backpack_fdatasync(value val_fd)
{
	CAMLparam1(val_fd);
	int r;

	caml_enter_blocking_section();
	r = fdatasync(Int_val(val_fd));
	caml_leave_blocking_section();

	if (r == -1)
		uerror("fdatasync", Nothing);

	CAMLreturn(Val_unit);
}
