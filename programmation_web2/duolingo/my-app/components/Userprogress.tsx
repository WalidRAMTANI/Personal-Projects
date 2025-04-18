import Link from 'next/link';
import React from 'react'
import { Button } from '@/components/ui/button';
import Image from 'next/image';
import { InfinityIcon } from 'lucide-react';

type props = {
    ActiveCourse: {ImageSrc: string; title: string},
    points: number,
    hearts: number,
    HasActiveSubscription: boolean
}
export function Userprogress({ActiveCourse, points, hearts, HasActiveSubscription}: props) {
  return (
    <div className='flex w-full items-center justify-between gap-x-2'>
        <Link href={"/courses"}>
            <Button variant={'ghost'}>
                <Image src={ActiveCourse.ImageSrc} alt={ActiveCourse.title} width={32} height={32} className='border rounded-md'/>
            </Button>
        </Link>
        <Link href={"/shop"}>
            <Button variant={"ghost"} className='text-orange-500'>
                <Image src={"/points.svg"} height={28} width={28} alt='Points' className='mr-2'/>
                {points}
            </Button>
        </Link>
        <Link href={"/shop"}>
            <Button variant={"ghost"} className='text-rose-500'>
                <Image src={"/heart.svg"} height={22} width={22} alt='hearts' className='mr-2'/>
                {HasActiveSubscription? <InfinityIcon className='w-4 h-4 text-neutral-400 stroke-3'/>: hearts}
            </Button>
        </Link>
    </div>
  )
}