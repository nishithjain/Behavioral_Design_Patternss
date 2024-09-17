
#include "EmailUser.h"
#include "ProductNotifier.h"
#include "SMSUser.h"

int main()
{
	// Create a product notifier (Publisher)
	ProductNotifier product("Smartphone");

	// Create users (Observers)
	const std::shared_ptr<IUser> nishith = std::make_shared<EmailUser>("Nishith");
	const std::shared_ptr<IUser> bob = std::make_shared<SMSUser>("Bob");

	// Users subscribe for notifications
	product.Subscribe(nishith);
	product.Subscribe(bob);

	// Product comes back in stock
	product.SetInStock(true);

	// Bob unsubscribes
	product.Unsubscribe(bob);

	return 0;
}
