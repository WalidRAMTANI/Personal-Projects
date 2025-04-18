import React from 'react';
import Image from 'next/image';
import { ClerkLoading, ClerkLoaded, SignedIn, SignedOut, UserButton , SignInButton} from '@clerk/nextjs';
import { Loader } from 'lucide-react';
import { Button } from '@/components/ui/button';
export function Header() {
  return (
    <header className='h-20 w-full border-b-2 border-slate-200 px-4'>
        <div className='h-20 lg:max-w-screen-lg mx-auto flex items-center justify-between'>
          <div className='pt-8 pl-4 pb-7 flex items-center gap-x-3'>
            <Image src="/mascot.svg" width={40} height={40} alt=''/>
            <h1 className='text-2xl font-extrabold text-green-600 tracking-wide'>Duolingo</h1>
          </div>
          <div>
            <ClerkLoading>
              <Loader className='w-5 h-5 text-muted-foreground animate-spin'/>
            </ClerkLoading>
              <ClerkLoaded>
                  <UserButton showName/>
                <SignedOut>
                  <SignInButton mode='modal'>
                    <Button size={"lg"} variant={"ghost"}>
                      Login
                    </Button>
                  </SignInButton>
                </SignedOut>
              </ClerkLoaded>
            </div>
        </div>
    </header>
  )
}