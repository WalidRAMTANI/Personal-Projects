'use client';
import React from 'react'
import Image from 'next/image'
import { Button } from '@/components/ui/button'
import { ClerkLoaded, ClerkLoading, SignInButton, SignUpButton, SignedIn, SignedOut } from '@clerk/nextjs'
import { Loader } from 'lucide-react'
import Link from 'next/link'
function page() {
  return (
    <div className='max-w-[988px] flex-1 w-full mx-auto flex flex-col lg:flex-row justify-center items-center p-4 gap-2'>
        <div className='relative w-[240px] h-[240px] lg:h-[424px] lg:w-[424px] mb-8 lg:mb-0'>
          <Image src="/hero.svg" fill alt="hero"/>
        </div>
        <div className='flex flex-col items-center gap-y-8'>
            <h1 className='text-xl text-center lg:text-3xl font-bold max-w-[480px] text-neutral-600'>
              Learn, practice and master Languages with Duolingo
            </h1>
            <div className='flex flex-col gap-y-5 max-w-[330px] w-full items-center'>
              <ClerkLoading>
                <Loader className='w-5 h-5 text-muted-foreground animate-spin'/>
              </ClerkLoading>
              <ClerkLoaded>
                <SignedIn>
                    <Button className='w-full' size={'lg'} variant={"secondry"}>Continue learning</Button>
                </SignedIn>
                <SignedOut>
                  <SignUpButton>
                    <Button className='w-full' size={'lg'} variant={"secondry"} asChild>
                      <Link href={"/learn"} >Get started</Link>
                      </Button>
                  </SignUpButton>
                  <SignInButton mode='modal'>
                    <Button className='w-full' size={"lg"} variant={"primaryOutline"}>I already have an account</Button>
                  </SignInButton>
                </SignedOut>
              </ClerkLoaded>
            </div>
        </div>
    </div>
  )
}

export default page 